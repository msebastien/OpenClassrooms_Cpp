#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QGridLayout *layout = new QGridLayout; // On peut spécifier le parent du layout comme étant la fenêtre

    QPushButton *button1 = new QPushButton("OK");
    QPushButton *button2 = new QPushButton("Options");
    QPushButton *button3 = new QPushButton("Quitter");
    QLineEdit *textBox = new QLineEdit;

    layout->addWidget(textBox, 0, 0, 1, 2);
    layout->addWidget(button1, 0, 2);
    layout->addWidget(button2, 1, 0, 1, 3);
    layout->addWidget(button3, 2, 0, 1, 3);

    window.setLayout(layout);

    window.show();

    return app.exec();
}
