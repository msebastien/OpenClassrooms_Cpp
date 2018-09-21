#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;

    QLineEdit *name = new QLineEdit;
    QLineEdit *firstName = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QLineEdit *text = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre &nom", name); // & -> définit un raccourci clavier. Ici, Ctrl + N
    layout->addRow("Votre &prénom", firstName);
    layout->addRow("Votre â&ge", age);
    layout->addRow("Numéro && Rue", text);

    window.setLayout(layout);

    window.show();

    return app.exec();
}
