#include "mainwindow.h"
#include <QCoreApplication>

/*namespace Ui {
   class MainWindow;
}*/



// MainWindow constructor
MainWindow::MainWindow(int width, int height, QWidget *parent) : QMainWindow(parent)
{
    // Set Window size
    this->setFixedSize(width, height);

    // Define default font and icon
    m_font = new QFont("Ubuntu", 20, QFont::Bold);

    // Create the button, make "this" the parent
    m_button = new QPushButton("Play", this);

    // set size and location of the button
    m_button->setGeometry(QRect(QPoint(150, 0), QSize(500, 50)));

    // Set Cursor
    m_button->setCursor(Qt::PointingHandCursor);

    // Set Icon
    m_button->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/play.png"));
    m_button->setIconSize(QSize(128, 128));

    // Set Font
    m_button->setFont(*m_font);
    m_button->setToolTip("Texte d'aide");
    m_button->show();

    // Connect button signal to appropriate slot
    QObject::connect(m_button, SIGNAL (released()), this, SLOT(handleButton()));
    QObject::connect(m_button, SIGNAL (released()), qApp, SLOT(aboutQt()));
}

void MainWindow::handleButton()
{
    // change the text
    m_button->setText("Pause");

    // change icon
    m_button->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/pause.png"));

    // resize button
    //m_button->resize(100,100);
}
