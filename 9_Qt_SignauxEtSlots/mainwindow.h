#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include <QSlider>
#include <QProgressBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *m_quitButton;
    QPushButton *m_resetButton;
    QFont *m_font;

    QLCDNumber *m_lcd;
    QSlider *m_slider;
    QProgressBar *m_progressBar;

public:
    explicit MainWindow(int width = 800, int height = 600, QWidget *parent = nullptr);

// Un signal peut passer un ou plusieurs paramètres. Dans notre cas, il n'en envoie aucun.
// Un signal doit toujours renvoyer void.
signals:
    void maxEnlargement();

public slots:
    void changeHeight(int height);
};

#endif // MAINWINDOW_H
