#include <QCoreApplication>
#include "mainwindow.h"
#include "browser.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    tabs = new QTabWidget;
    tabs->setTabsClosable(true);
    tabs->setMovable(true);
    setCentralWidget(tabs);

    // Generate Tabs and loading Home Page
    tabs->addTab(createWebPageTab(Browser::homePageUrl), "New Tab");

    // Définition de quelques propriétés de la fenêtre
    setMinimumSize(500, 350);
    setWindowIcon( QIcon(QPixmap("icons/apps/64/internet-web-browser.svg")) );
    setWindowTitle(Browser::name);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));


    //EVENTS
    connect(tabs, SIGNAL(tabCloseRequested(int)), this, SLOT(closeIndexedTab(int)));
    connect(urlBar, SIGNAL(returnPressed()), goToAction, SLOT(triggered()));

    connect(goToAction, SIGNAL(triggered()), this, SLOT(updateWebPage()));
    connect(tabs, SIGNAL(currentChanged(int)), this, SLOT(updateTab(int)));

}

QWidget* MainWindow::createWebPageTab(QString const& url)
{
    QWidget *tabPage = new QWidget;
    QWebEngineView *webView = new QWebEngineView;
    QString webAddress(url);

    QVBoxLayout *tabLayout = new QVBoxLayout;
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->addWidget(webView);
    tabPage->setLayout(tabLayout);

    if (webAddress.isEmpty())
    {
        webView->load(QUrl("html/blank_page.html"));
    }
    else
    {
        if (!webAddress.startsWith("http"))
        {
            webAddress = "http://" + webAddress;
        }
        webView->load(QUrl(webAddress));
    }

    // EVENTS
    connect(webView, SIGNAL(titleChanged(QString)), this, SLOT(updateTitle(QString)));
    connect(webView, SIGNAL(urlChanged(QUrl)), this, SLOT(updateUrl(QUrl)));
    connect(webView, SIGNAL(loadStarted()), this, SLOT(loadBegin()));
    connect(webView, SIGNAL(loadProgress(int)), this, SLOT(updateLoadingProgress(int)));
    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadCompleted(bool)));

    return tabPage;
}

QWebEngineView *MainWindow::currentWebPage()
{
    return tabs->currentWidget()->findChild<QWebEngineView *>();
}

//------------------------------------------------------------------------------------
//  SLOTS
//------------------------------------------------------------------------------------
void MainWindow::updateTitle(QString const& completeTitle)
{
    QString shortTitle = completeTitle;

    // We shorten titles to avoid having too large tabs
    if (completeTitle.size() > 40)
    {
        shortTitle = completeTitle.left(40) + "...";
    }

    setWindowTitle(shortTitle + " - " + Browser::name);
    tabs->setTabText(tabs->currentIndex(), shortTitle);
}

void MainWindow::updateUrl(QUrl const& url)
{
    if (url.toString() != tr("html/blank_page.html"))
    {
        urlBar->setText(url.toString());
    }
}

// Update Tab each time we switch tab
void MainWindow::updateTab(int index)
{
    updateTitle(currentWebPage()->title());
    updateUrl(currentWebPage()->url());
}

void MainWindow::loadBegin()
{
    windowStatusBar->show();
}

void MainWindow::updateLoadingProgress(int progress)
{
    pageLoadProgressBar->setValue(progress);
}

void MainWindow::loadCompleted(bool finished)
{
    if(finished)
    {
        windowStatusBar->hide();
        pageLoadProgressBar->setValue(0);

        QNetworkReply* reply = manager->get(QNetworkRequest(currentWebPage()->iconUrl()));

        QByteArray iconData= reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(iconData);

        QIcon favIcon(pixmap);
        tabs->setTabIcon(tabs->currentIndex(), favIcon);
    }
}

void MainWindow::openNewTab()
{
    int indexNewTab = tabs->addTab(createWebPageTab(Browser::homePageUrl), "New Tab");
    tabs->setCurrentIndex(indexNewTab);

    urlBar->setText("");
    urlBar->setFocus(Qt::OtherFocusReason);
}

void MainWindow::closeCurrentTab()
{
    if(tabs->count() > 1)
    {
        currentWebPage()->close();
        tabs->currentWidget()->findChild<QWidget*>()->close();
        tabs->removeTab(tabs->currentIndex());
    }
    else
    {
        qApp->quit();
    }

}

void MainWindow::closeIndexedTab(int index)
{
    if(tabs->count() > 1)
    {
        tabs->widget(index)->findChild<QWebEngineView*>()->close();
        tabs->widget(index)->findChild<QWidget*>()->close();
        tabs->removeTab(index);
    }
    else
    {
        qApp->quit();
    }

}

// Update Web Page when we enter a new URL
// Thus, the tab is also updated by updateTab()
void MainWindow::updateWebPage()
{
    QString url = urlBar->text();

    // On rajoute le "http://" s'il n'est pas déjà dans l'adresse
    if (!url.startsWith("http"))
    {
        url = "http://" + url;
        urlBar->setText(url);
    }

    currentWebPage()->load(QUrl(url));
}

void MainWindow::goToPreviousPage()
{
    currentWebPage()->back();
}

void MainWindow::goToNextPage()
{
    currentWebPage()->forward();
}

void MainWindow::goToHomePage()
{
    currentWebPage()->load(QUrl(Browser::homePageUrl));
}

void MainWindow::stop()
{
    currentWebPage()->stop();
}

void MainWindow::refresh()
{
    currentWebPage()->reload();
}

void MainWindow::openGeneralMenu()
{
    openGeneralMenuAction->menu()->exec();
}

//-------------------------------------------------------------------------------------
//  INIT WINDOW
//--------------------------------------------------------------------------------------
void MainWindow::createActions()
{
    openGeneralMenuAction = new QAction("Open the menu", this);
    openGeneralMenuAction->setIcon(QIcon( QIcon::fromTheme("open-menu", QPixmap("icons/actions/24/open-menu.svg")) ));

    openTabAction = new QAction("Open a new tab", this);
    openTabAction->setShortcut(QKeySequence("Ctrl+T"));
    openTabAction->setIcon(QIcon( QIcon::fromTheme("window-new", QPixmap("icons/actions/24/window-new.svg")) ));

    closeTabAction = new QAction("Close tab", this);
    closeTabAction->setShortcut(QKeySequence("Ctrl+W"));
    //closeTabAction->setIcon(QIcon( QIcon::fromTheme("window-close", QPixmap(":/icons/actions/16/window-close.svg")) ));

    quitAppAction = new QAction("&Quit", this);
    quitAppAction->setShortcut(QKeySequence("Ctrl+Q"));

    nextPageAction = new QAction("Next page", this);
    nextPageAction->setIcon(QIcon( QIcon::fromTheme("go-next", QPixmap("icons/actions/24/go-next.svg")) ));

    previousPageAction = new QAction("Previous page", this);
    previousPageAction->setIcon(QIcon( QIcon::fromTheme("go-previous", QPixmap("icons/actions/24/go-previous.svg")) ));

    refreshPageAction = new QAction("Refresh page", this);
    refreshPageAction->setShortcut(QKeySequence("Ctrl+R"));
    refreshPageAction->setIcon(QIcon( QIcon::fromTheme("view-refresh", QPixmap("icons/actions/24/view-refresh.svg")) ));

    goToHomePageAction = new QAction("Go to home page", this);
    goToHomePageAction->setIcon(QIcon( QIcon::fromTheme("go-home", QPixmap("icons/actions/24/go-home.svg")) ));

    goToAction = new QAction("Go to this URL", this);
    goToAction->setIcon(QIcon( QIcon::fromTheme("media-playback-start", QPixmap("icons/actions/24/media-playback-start.svg")) ));

    aboutAppAction = new QAction("About", this);
    aboutAppAction->setIcon(QIcon( QIcon::fromTheme("help-about", QPixmap("icons/actions/24/help-about.svg")) ));

    // EVENTS
    connect(openGeneralMenuAction, SIGNAL(triggered()), this, SLOT(openGeneralMenu()));

    connect(quitAppAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(openTabAction, SIGNAL(triggered()), this, SLOT(openNewTab()));
    connect(closeTabAction, SIGNAL(triggered()), this, SLOT(closeCurrentTab()));

    connect(previousPageAction, SIGNAL(triggered()), this, SLOT(goToPreviousPage()));
    connect(nextPageAction, SIGNAL(triggered()), this, SLOT(goToNextPage()));
    connect(goToHomePageAction, SIGNAL(triggered()), this, SLOT(goToHomePage()));
    connect(refreshPageAction, SIGNAL(triggered()), this, SLOT(refresh()));

}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(openTabAction);
    fileMenu->addAction(closeTabAction);
    fileMenu->addAction(quitAppAction);

    QMenu *browseMenu = menuBar()->addMenu("&Browse");
    browseMenu->addAction(nextPageAction);
    browseMenu->addAction(previousPageAction);
    browseMenu->addAction(refreshPageAction);
    browseMenu->addAction(goToHomePageAction);

    QMenu *helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction("About Qt");
    helpMenu->addAction(aboutAppAction);

    generalMenu = new QMenu("General Menu");
    generalMenu->addAction(openTabAction);
    generalMenu->addSeparator();
    generalMenu->addAction(aboutAppAction);
    generalMenu->addAction(quitAppAction);
    openGeneralMenuAction->setMenu(generalMenu);

}

void MainWindow::createToolBars()
{
    browseToolBar = addToolBar("Browse");

    browseToolBar->addAction(previousPageAction);
    browseToolBar->addAction(nextPageAction);
    browseToolBar->addAction(refreshPageAction);
    browseToolBar->addAction(goToHomePageAction);

    urlBar = new QLineEdit;
    browseToolBar->addWidget(urlBar);

    browseToolBar->addAction(goToAction);
    browseToolBar->addAction(openGeneralMenuAction);
}

void MainWindow::createStatusBar()
{
    windowStatusBar = statusBar();
    windowStatusBar->hide();
    pageLoadProgressBar = new QProgressBar;

    windowStatusBar->addWidget(pageLoadProgressBar);
}
