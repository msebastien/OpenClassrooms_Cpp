#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStyle>
#include <QtWebEngineWidgets>

class MainWindow : public QMainWindow
{
        Q_OBJECT
    private:
        QNetworkAccessManager *manager;
        // ACTIONS
        QAction *openGeneralMenuAction;

        QAction *openTabAction;
        QAction *closeTabAction;
        QAction *quitAppAction;

        QAction *nextPageAction;
        QAction *previousPageAction;
        QAction *refreshPageAction;
        QAction *goToHomePageAction;
        QAction *goToAction;

        QAction *aboutAppAction;

        // MENUS
        QMenu *generalMenu;
        QMenu *fileMenu;
        QMenu *browseMenu;
        QMenu *helpMenu;

        // TOOLBARS
        QToolBar *browseToolBar;
        QStatusBar *windowStatusBar;

        // LAYOUTS
        QVBoxLayout *mainWindowLayout;
        QHBoxLayout *toolBarLayout;
        QHBoxLayout *statusBarLayout;

        // WIDGETS
        QLineEdit *urlBar;
        QTabWidget *tabs;
        QProgressBar *pageLoadProgressBar;

        // INIT
        void createActions();
        void createMenus();
        void createToolBars();
        void createStatusBar();

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        QWidget *createWebPageTab(QString const& url);
        QWebEngineView *currentWebPage();
    signals:

    public slots:
        void updateTitle(QString const& completeTitle);
        void updateUrl(QUrl const& url);
        void updateTab(int);
        void openGeneralMenu();

        // Loading
        void loadBegin();
        void updateLoadingProgress(int);
        void loadCompleted(bool);

        // Tab management
        void openNewTab();
        void closeCurrentTab();
        void closeIndexedTab(int);
        void updateWebPage();

        // Browsing management
        void goToPreviousPage();
        void goToNextPage();
        void goToHomePage();
        void stop();
        void refresh();
};

#endif // MAINWINDOW_H
