#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QHBoxLayout *layout = new QHBoxLayout; // On peut spécifier le parent du layout comme étant la fenêtre

    QPushButton *button1 = new QPushButton("Bonjour");
    QPushButton *button2 = new QPushButton("les");
    QPushButton *button3 = new QPushButton("Zéros");

    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    window.setLayout(layout); // Inutile si on a spécifié le parent précédemment

    window.show();

    return app.exec();
}
