#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QDateEdit>
#include <QDate>
#include <QPushButton>
#include <QString>
#include <QMessageBox>


class MainWindow : public QWidget
{
        Q_OBJECT
    private:
        // Layouts
        QVBoxLayout *mainLayout;
        QFormLayout *classDefinitionLayout;
        QVBoxLayout *optionsLayout;
        QFormLayout *commentsLayout;
        QGridLayout *buttonBoxLayout;

        // Group Boxes
        QGroupBox *classDefinition;
        QGroupBox *options;
        QGroupBox *comments;

        // Text Boxes
        QLineEdit *classNameTextBox;
        QLineEdit *parentClassTextBox;
        QLineEdit *authorNameTextBox;
        QTextEdit *classRoleDescriptionTextBox;

        // Check Boxes
        QCheckBox *protectHeaderMultipleInclusionCheckBox;
        QCheckBox *generateDefaultConstructorCheckBox;
        QCheckBox *generateDestructorCheckBox;

        // Spin Box
        QDateEdit *creationDateSpinBox;

        // Buttons
        QPushButton *generateClassButton;
        QPushButton *quitButton;

    public:
        explicit MainWindow(QWidget *parent = nullptr);

    signals:
        void classNameMissing();

    public slots:
        void generateCode();
        void displayMissingClassNameError();
};

#endif // MAINWINDOW_H
