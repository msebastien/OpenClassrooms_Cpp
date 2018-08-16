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

    //  QUIT
    m_quitButton = new QPushButton("Quitter", this);
    m_quitButton ->setFont(QFont("Ubuntu", 14));
    m_quitButton ->move(350, 0);
    QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    // LCD and Slider
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(350, 50);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(320, 80, 150, 20);
    m_slider->setRange(200, 800);

    // Il suffit d'indiquer le type du paramètre envoyé, ici un int, sans donner de nom à ce paramètre.
    // Qt fait automatiquement la connexion entre le signal et le slot et « transmet » le paramètre au slot.
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changeHeight(int)));
    QObject::connect(this, SIGNAL(maxEnlargement()), qApp, SLOT(quit()));

    // Progress Bar
    m_progressBar = new QProgressBar(this);
    m_progressBar->setGeometry(320, 100, 150, 20);
    m_progressBar->setRange(200, 800);
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_progressBar, SLOT(setValue(int)));

    // Reset
    m_resetButton = new QPushButton("Reset", this);
    m_resetButton ->setFont(QFont("Ubuntu", 14));
    m_resetButton ->move(350, 130);
    QObject::connect(m_resetButton, SIGNAL(clicked()), m_progressBar, SLOT(reset()));
    QObject::connect(m_progressBar, SIGNAL(valueChanged(int)), m_slider, SLOT(setValue(int)));
    QObject::connect(m_progressBar, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
}

void MainWindow::changeHeight(int height)
{
    this->setFixedHeight(height);

    if(height >= 700)
    {
        emit maxEnlargement();
    }
}
