#ifndef GENERATEDCLASSWINDOW_H
#define GENERATEDCLASSWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QTabWidget>


class GeneratedClassWindow : public QDialog
{
        Q_OBJECT
    private:
        QVBoxLayout *mainLayout;
        QVBoxLayout *headerLayout;
        QVBoxLayout *sourceLayout;
        QTextEdit *generatedHeaderCodeTextBox;
        QTextEdit *generatedSourceCodeTextBox;
        QPushButton *closeButton;
    public:
        GeneratedClassWindow(QString& headerCode, QString& className, QWidget *parent = nullptr);

    signals:

    public slots:
};

#endif // GENERATEDCLASSWINDOW_H
