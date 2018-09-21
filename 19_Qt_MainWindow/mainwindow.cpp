#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // SDI (Single Document Interface)
    /*QWidget *centralZone = new QWidget;

    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre nom", nom);
    layout->addRow("Votre prénom", prenom);
    layout->addRow("Votre âge", age);

    centralZone->setLayout(layout);
    setCentralWidget(centralZone);*/

    // MDI (Multiple Document Interface) = Sub Windows
    QMdiArea *centralZone = new QMdiArea;

    QTextEdit *textArea1 = new QTextEdit;
    QTextEdit *textArea2 = new QTextEdit;

    QMdiSubWindow *subWindow1 = centralZone->addSubWindow(textArea1);
    QMdiSubWindow *subWindow2 = centralZone->addSubWindow(textArea2);

    setCentralWidget(centralZone);

    //===MENU BAR===
    // FILE MENU
    QMenu *fileMenu = menuBar()->addMenu("&Fichier");

    //Sub Menu
    QMenu *recentFiles = fileMenu->addMenu("Fichiers &récents");
    recentFiles->addAction("Fichier bidon 1.txt"); // Need to recover pointers to Actions for Signals/Slots
    recentFiles->addAction("Fichier bidon 2.txt"); // For contextual menus, see QWidget documentation
    recentFiles->addAction("Fichier bidon 3.txt");
    // End Sub Menu

    QAction *quitAction = new QAction("&Quitter", this);
    quitAction->setShortcut(QKeySequence("Ctrl+Q"));
    quitAction->setIcon(QIcon("quit.png"));
    fileMenu->addAction(quitAction);

    // EDIT MENU
    QMenu *editMenu = menuBar()->addMenu("&Edition");
    QAction *boldAction = new QAction("&Gras", this);
    boldAction->setShortcut(QKeySequence("Ctrl+G"));
    boldAction->setCheckable(true);
    editMenu->addAction(boldAction);

    // VIEW MENU
    QMenu *viewMenu = menuBar()->addMenu("&Affichage");

    //===TOOL BAR===
    QToolBar *fileToolBar = addToolBar("Fichier");
    fileToolBar->addAction(quitAction);

    fileToolBar->addSeparator();

    QFontComboBox *fontChoice = new QFontComboBox;
    fileToolBar->addWidget(fontChoice);

    // EVENTS
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}
