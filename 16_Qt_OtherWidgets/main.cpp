#include <QApplication>
#include <QtWidgets>
#include <unistd.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    QDialog secondaryWindow;

    // INNER LAYOUT
    QGroupBox *groupbox = new QGroupBox("Votre plat préféré");

    QRadioButton *steacks = new QRadioButton("Les steacks");
    QRadioButton *hamburgers = new QRadioButton("Les hamburgers");
    QRadioButton *nuggets = new QRadioButton("Les nuggets");
    QCheckBox *checkbox = new QCheckBox("J'aime les frites");

    steacks->setChecked(true);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(steacks);
    vbox->addWidget(hamburgers);
    vbox->addWidget(nuggets);
    vbox->addWidget(checkbox);
    groupbox->setLayout(vbox);
    groupbox->move(5, 5);

    // MAIN LAYOUT
    QVBoxLayout *mainLayout = new QVBoxLayout(&fenetre);
    QPushButton *button = new QPushButton("Valider");

    mainLayout->addWidget(groupbox);
    mainLayout->addWidget(button);

    // SECONDARY WINDOW
    QVBoxLayout *dialogLayout = new QVBoxLayout(&secondaryWindow);

    // ==IMAGE==
    QLabel *label = new QLabel(&secondaryWindow);
    //label->setPixmap(QPixmap("loading.gif")); // No animation
    QMovie *movie = new QMovie("loading.gif");
    label->setMovie(movie);
    movie->start();
    //==PROGRESS BAR==
    QProgressBar *bar = new QProgressBar;
    bar->setValue(100);

    //==LINE EDIT==
    QLineEdit *lineEdit = new QLineEdit;
    lineEdit->setEchoMode(QLineEdit::Password);

    //==TEXT EDIT==
    QTextEdit *textEdit = new QTextEdit;

    //==SPIN BOX==
    QSpinBox *spinBox = new QSpinBox;
    spinBox->setValue(0);
    spinBox->setAccelerated(true);
    spinBox->setSingleStep(10);
    spinBox->setSuffix("€");

    //==DOUBLE SPIN BOX==
    QDoubleSpinBox *doubleSpinBox = new QDoubleSpinBox;
    doubleSpinBox->setValue(0);
    doubleSpinBox->setAccelerated(true);
    doubleSpinBox->setSingleStep(10);
    doubleSpinBox->setSuffix("€");

    //==SLIDER==
    QSlider *slider = new QSlider(Qt::Horizontal);

    //==COMBO BOX==
    QComboBox *liste = new QComboBox;
    liste->addItem("Paris");
    liste->addItem("Londres");
    liste->addItem("Singapour");
    liste->addItem("Tokyo");

    dialogLayout->addWidget(label);
    dialogLayout->addWidget(bar);
    dialogLayout->addWidget(lineEdit);
    dialogLayout->addWidget(textEdit);
    dialogLayout->addWidget(spinBox);
    dialogLayout->addWidget(doubleSpinBox);
    dialogLayout->addWidget(slider);
    dialogLayout->addWidget(liste);

    QObject::connect(button, SIGNAL(clicked()), &secondaryWindow, SLOT(exec()));


    fenetre.show();

    return app.exec();
}
