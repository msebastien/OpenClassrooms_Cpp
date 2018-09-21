#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    // FORM LAYOUT
    QFormLayout *formLayout = new QFormLayout;
    QLineEdit *name = new QLineEdit;
    QLineEdit *firstName = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QLineEdit *text = new QLineEdit;

    formLayout->addRow("Votre &nom", name); // & -> définit un raccourci clavier. Ici, Ctrl + N
    formLayout->addRow("Votre &prénom", firstName);
    formLayout->addRow("Votre â&ge", age);
    formLayout->addRow("N&uméro && Rue", text);

    // MAIN LAYOUT
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(formLayout);

    QPushButton *button = new QPushButton("Quitter");
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
    mainLayout->addWidget(button);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
