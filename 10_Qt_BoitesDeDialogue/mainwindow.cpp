#include <QCoreApplication>

#include "mainwindow.h"

/*namespace Ui {
   class MainWindow;
}*/

// MainWindow constructor
MainWindow::MainWindow(int width, int height, QWidget *parent) : QMainWindow(parent)
{
    // Set Window size
    this->setFixedSize(width, height);

    // Define default font and icon
    m_font = new QFont("Ubuntu", 14);

    // Informaion Dialog Button
    m_informationDialogButton = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_informationDialogButton->setGeometry(275, 30, 250, 30);
    m_informationDialogButton->setFont(*m_font);
    QObject::connect(m_informationDialogButton, SIGNAL(clicked()), this, SLOT(openInformationMessageBox()));

    // Warning Dialog Button
    m_warningDialogButton = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_warningDialogButton->setGeometry(275, 60, 250, 30);
    m_warningDialogButton->setFont(*m_font);
    QObject::connect(m_warningDialogButton, SIGNAL(clicked()), this, SLOT(openWarningMessageBox()));

    // Critical Dialog Button
    m_criticalDialogButton = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_criticalDialogButton->setGeometry(275, 90, 250, 30);
    m_criticalDialogButton->setFont(*m_font);
    QObject::connect(m_criticalDialogButton, SIGNAL(clicked()), this, SLOT(openCriticalMessageBox()));

    // Question Dialog Button
    m_questionDialogButton = new QPushButton("Ouvrir la boîte de dialogue", this);
    m_questionDialogButton->setGeometry(275, 120, 250, 30);
    m_questionDialogButton->setFont(*m_font);
    QObject::connect(m_questionDialogButton, SIGNAL(clicked()), this, SLOT(openQuestionMessageBox()));

    // Text Input Dialog Button
    m_textInputDialogButton = new QPushButton("Saisir une information", this);
    m_textInputDialogButton->setGeometry(275, 180, 250, 30);
    m_textInputDialogButton->setFont(*m_font);
    QObject::connect(m_textInputDialogButton, SIGNAL(clicked()), this, SLOT(openTextInputDialog()));
    QObject::connect(this, SIGNAL(pseudoRetrieved(QString)), this, SLOT(setButtonText(QString))); // Rename text button with pseudo

    // Font Selection Dialog
    m_fontSelectionDialogButton = new QPushButton("Changer la police", this);
    m_fontSelectionDialogButton->setGeometry(275, 210, 250, 30);
    m_fontSelectionDialogButton->setFont(*m_font);
    QObject::connect(m_fontSelectionDialogButton, SIGNAL(clicked()), this, SLOT(openFontSelectionDialogBox()));

    // Color Selection Dialog
    m_colorSelectionDialogButton = new QPushButton("Changer la couleur", this);
    m_colorSelectionDialogButton->setGeometry(275, 240, 250, 30);
    m_colorSelectionDialogButton->setFont(*m_font);
    QObject::connect(m_colorSelectionDialogButton, SIGNAL(clicked()), this, SLOT(openColorSelectionDialogBox()));

    // Directory Selection Dialog
    m_directorySelectionDialogButton = new QPushButton("Sélectionner un répertoire", this);
    m_directorySelectionDialogButton->setGeometry(275, 300, 250, 30);
    m_directorySelectionDialogButton->setFont(*m_font);
    QObject::connect(m_directorySelectionDialogButton, SIGNAL(clicked()), this, SLOT(openDirectorySelectionDialogBox()));

    // File Selection Dialog
    m_fileSelectionDialogButton = new QPushButton("Sélectionner un fichier", this);
    m_fileSelectionDialogButton->setGeometry(275, 330, 250, 30);
    m_fileSelectionDialogButton->setFont(*m_font);
    QObject::connect(m_fileSelectionDialogButton, SIGNAL(clicked()), this, SLOT(openFileSelectionDialogBox()));

    // File Save Dialog
    m_fileSaveDialogButton = new QPushButton("Enregistrer un fichier vide", this);
    m_fileSaveDialogButton->setGeometry(275, 360, 250, 30);
    m_fileSaveDialogButton->setFont(*m_font);
    QObject::connect(m_fileSaveDialogButton, SIGNAL(clicked()), this, SLOT(openFileSaveDialogBox()));



    //  QUIT
    m_quitButton = new QPushButton("Quitter", this);
    m_quitButton->setFont(*m_font);
    m_quitButton->move(350, 0);
    QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

}

void MainWindow::openInformationMessageBox()
{
    QMessageBox::information(this, "Information", "Vous avez ouvert cette boîte de dialogue.<br />Cliquez sur <strong>OK</strong> pour fermer.");
}

void MainWindow::openWarningMessageBox()
{
    QMessageBox::warning(this, "Avertissement", "Attention ! Il semblerait que vous êtes un vilain pas beau.");
}

void MainWindow::openCriticalMessageBox()
{
    QMessageBox::critical(this, "Erreur critique", "Erreur 500 : Internal Server Error");
}

void MainWindow::openQuestionMessageBox()
{
    int response = QMessageBox::question(this, "Question", "Aimez-vous le framework Qt ?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes)
        {
            QMessageBox::information(this, "Interrogatoire", "Alors bienvenue chez les Zéros !");
        }
        else if (response == QMessageBox::No)
        {
            QMessageBox::critical(this, "Interrogatoire", "Tricheur ! Menteur ! Voleur ! Ingrat ! Lâche ! Traître !\nSors d'ici ou j'appelle la police !");
        }
}

void MainWindow::openTextInputDialog()
{
    QString pseudo;
    bool ok = false;
    pseudo = QInputDialog::getText(this, "Pseudonyme", "Quel est votre pseudo ?", QLineEdit::Normal, QString(), &ok);

    if (ok && !pseudo.isEmpty())
        {
            QMessageBox::information(this, "Pseudonyme", "Bonjour <strong>" + pseudo + "</strong>, ça va ?");
            emit pseudoRetrieved(pseudo);
        }
        else
        {
            QMessageBox::critical(this, "Pseudonyme", "Vous n'avez pas voulu donner votre nom… snif.");
        }

}

void MainWindow::openFontSelectionDialogBox()
{
    bool ok = false;

    QFont selectedFont = QFontDialog::getFont(&ok, m_fontSelectionDialogButton->font(), this, "Choisissez une police");

    if (ok)
    {
        *m_font = selectedFont;
        m_fontSelectionDialogButton->setFont(*m_font);
    }
}

void MainWindow::openColorSelectionDialogBox()
{
    QColor selectedColor = QColorDialog::getColor(Qt::black, this, "Choisissez une couleur");

    QPalette palette;
    palette.setColor(QPalette::ButtonText, selectedColor);
    this->setPalette(palette);
}

void MainWindow::openDirectorySelectionDialogBox()
{
    QString directory = QFileDialog::getExistingDirectory(this);
    QMessageBox::information(this, "Répertoire", "Vous avez sélectionné :<br /><strong>" + directory + "</strong>.");

}

void MainWindow::openFileSelectionDialogBox()
{
    QString file = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :<br /><strong>" + file + "</strong>.");
}

void MainWindow::openFileSaveDialogBox()
{
    QString file = QFileDialog::getSaveFileName(this, "Enregistrer un fichier image vide", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    QMessageBox::information(this, "Fichier", "Vous avez créé ce fichier image vide :<br /><strong>" + file + "</strong>.");
}

void MainWindow::setButtonText(QString str)
{
    m_textInputDialogButton->setText("Bienvenue, " + str);
}


