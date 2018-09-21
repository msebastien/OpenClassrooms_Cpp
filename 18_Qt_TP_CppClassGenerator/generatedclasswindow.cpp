#include "generatedclasswindow.h"

GeneratedClassWindow::GeneratedClassWindow(QString& code, QString& className, QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Code généré");
    setFixedSize(600, 800);

    QTabWidget *tabs = new QTabWidget;
    QWidget *header = new QWidget;
    QWidget *source = new QWidget;

    // HEADER FILE
    headerLayout = new QVBoxLayout(header);
    generatedHeaderCodeTextBox = new QTextEdit;
    headerLayout->addWidget(generatedHeaderCodeTextBox);

    generatedHeaderCodeTextBox->setCurrentFont(QFont("Courier", 15));
    generatedHeaderCodeTextBox->setText(code);
    generatedHeaderCodeTextBox->setReadOnly(true);

    // SOURCE FILE
    sourceLayout = new QVBoxLayout(source);
    generatedSourceCodeTextBox = new QTextEdit;
    sourceLayout->addWidget(generatedSourceCodeTextBox);

    generatedSourceCodeTextBox->setCurrentFont(QFont("Courier", 15));
    generatedSourceCodeTextBox->setReadOnly(true);

    // ADD TABS
    tabs->addTab(header, className + ".h");
    tabs->addTab(source, className + ".cpp");

    // MAIN LAYOUT
    mainLayout = new QVBoxLayout(this);
    closeButton = new QPushButton(tr("Fermer"));

    mainLayout->addWidget(tabs);
    mainLayout->addWidget(closeButton);

    // EVENTS
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
}
