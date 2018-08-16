#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QFont>
#include <QIcon>

class MainWindow : public QMainWindow
{
  Q_OBJECT
private:
  QPushButton *m_button;
  QFont *m_font;
public:
  explicit MainWindow(int width = 800, int height = 600, QWidget *parent = nullptr);

private slots:
  void handleButton();
};

#endif // MAINWINDOW_H
