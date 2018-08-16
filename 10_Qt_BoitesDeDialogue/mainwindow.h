#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFont>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *m_quitButton;
    QPushButton *m_informationDialogButton;
    QPushButton *m_warningDialogButton;
    QPushButton *m_criticalDialogButton;
    QPushButton *m_questionDialogButton;

    QPushButton *m_textInputDialogButton;
    QPushButton *m_fontSelectionDialogButton;
    QPushButton *m_colorSelectionDialogButton;

    QPushButton *m_directorySelectionDialogButton;
    QPushButton *m_fileSelectionDialogButton;
    QPushButton *m_fileSaveDialogButton;

    QFont *m_font;

public:
    explicit MainWindow(int width = 800, int height = 600, QWidget *parent = nullptr);

signals:
    void pseudoRetrieved(QString pseudo);

public slots:
    void openInformationMessageBox();
    void openWarningMessageBox();
    void openCriticalMessageBox();
    void openQuestionMessageBox();

    void openTextInputDialog();
    void openFontSelectionDialogBox();
    void openColorSelectionDialogBox();
    void openDirectorySelectionDialogBox();
    void openFileSelectionDialogBox();
    void openFileSaveDialogBox();

    void setButtonText(QString str);
};

#endif // MAINWINDOW_H
