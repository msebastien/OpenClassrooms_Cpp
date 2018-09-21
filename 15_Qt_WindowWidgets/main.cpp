#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    QPushButton *button = new QPushButton("Ouvrir la fenêtre", &window);

    QDialog dialogWindow (&window);

    // Create image
    QLabel *image = new QLabel(&dialogWindow);
    image->setPixmap(QPixmap("icone.png"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(image);
    dialogWindow.setLayout(layout);


    QWidget::connect(button, SIGNAL(clicked()), &dialogWindow, SLOT(exec()));
    window.show();

    return app.exec();
}
