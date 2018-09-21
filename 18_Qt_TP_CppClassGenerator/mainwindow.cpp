#include <QCoreApplication>
#include "mainwindow.h"
#include "generatedclasswindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("C++ Class Generator");
    setWindowIcon(QIcon("icon.png"));

    // Class Definition
    classDefinition = new QGroupBox(tr("Définition de la classe"));
    classDefinitionLayout = new QFormLayout(classDefinition);

    classNameTextBox = new QLineEdit;
    parentClassTextBox = new QLineEdit;

    classDefinitionLayout->addRow(tr("&Nom :"), classNameTextBox);
    classDefinitionLayout->addRow(tr("Classe &parente :"), parentClassTextBox);

    // Options
    options = new QGroupBox(tr("Options"));
    optionsLayout = new QVBoxLayout(options);

    protectHeaderMultipleInclusionCheckBox = new QCheckBox(tr("Protéger le &header contre les inclusions multiples"));
    generateDefaultConstructorCheckBox = new QCheckBox(tr("Générer un &constructeur par défaut"));
    generateDestructorCheckBox = new QCheckBox(tr("Générer un &destructeur"));

    optionsLayout->addWidget(protectHeaderMultipleInclusionCheckBox);
    optionsLayout->addWidget(generateDefaultConstructorCheckBox);
    optionsLayout->addWidget(generateDestructorCheckBox);

    // Comments
    comments = new QGroupBox(tr("Ajouter des commentaires"));
    comments->setCheckable(true);
    comments->setChecked(false);
    commentsLayout = new QFormLayout(comments);

    authorNameTextBox = new QLineEdit;
    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");
    authorNameTextBox->setText(name);

    creationDateSpinBox = new QDateEdit;
    creationDateSpinBox->setDate(QDate::currentDate());
    creationDateSpinBox->setCalendarPopup(true);
    classRoleDescriptionTextBox = new QTextEdit;

    commentsLayout->addRow(tr("&Auteur :"), authorNameTextBox);
    commentsLayout->addRow(tr("Da&te de création :"), creationDateSpinBox);
    commentsLayout->addRow(tr("&Rôle de la classe :"), classRoleDescriptionTextBox);

    // Buttons
    buttonBoxLayout = new QGridLayout;
    generateClassButton = new QPushButton(tr("Générer"));
    quitButton = new QPushButton(tr("Quitter"));

    buttonBoxLayout->addWidget(generateClassButton, 0, 3, 1, 1, Qt::AlignRight);
    buttonBoxLayout->addWidget(quitButton, 0, 4, 1, 1, Qt::AlignRight);
    buttonBoxLayout->setColumnStretch(3, 10);
    buttonBoxLayout->setColumnStretch(4, 1);

    // Window Main Layout
    mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(classDefinition);
    mainLayout->addWidget(options);
    mainLayout->addWidget(comments);
    mainLayout->addLayout(buttonBoxLayout);

    // Events
    connect(generateClassButton, SIGNAL(clicked()), this, SLOT(generateCode()));
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(this, SIGNAL(classNameMissing()), this, SLOT(displayMissingClassNameError()));
}

void MainWindow::generateCode()
{
    QString generatedCode;

    // CODE ELEMENTS
    QString inclusionProtectionBegin;
    QString inclusionProtectionEnd("#endif");
    QString beginDefClass;
    QString publicMethods;
    QString endDefClass;
    QString classComments;

    // CLASS DATA
    QString className = classNameTextBox->text();
    QString parentClass = parentClassTextBox->text();
    QString authorName = authorNameTextBox->text();
    QString creationDate = creationDateSpinBox->date().toString();
    QString classRole = classRoleDescriptionTextBox->toPlainText();

    // IF CLASS NAME IS MISSING
    if(className.isEmpty())
    {
        emit classNameMissing();
        return;
    }

    //==1. COMMENTS==
    classComments = "/*\n"; // begin

    if(!authorName.isEmpty()) classComments += "Auteur : " + authorName + "\n";
    classComments += "Date de création : " + creationDate + "\n";
    if(!classRole.isEmpty()) classComments += "Rôle :\n" + classRole;

    classComments += "\n*/\n\n"; // end

    //==2. INCLUSION PROTECTION==
    inclusionProtectionBegin = "#ifndef HEADER_" + className.toUpper()
                               + "\n#define HEADER_" + className.toUpper() + "\n\n";

    //==3. BEGIN DEF CLASS==
    beginDefClass = "class " + className;
    if(!parentClass.isEmpty()) beginDefClass += " : public " + parentClass + "\n{";
    else beginDefClass += " {";

    //==4. PUBLIC METHODS==
    publicMethods = "\n\tpublic:\n";
    if(generateDefaultConstructorCheckBox->isChecked())
        publicMethods += "\t\t"+ className + "();\n";

    if(generateDestructorCheckBox->isChecked())
        publicMethods += "\t\t~" + className + "();\n";

    //==5. END DEF CLASS==
    endDefClass = "\n\tprotected:\n\n\tprivate:\n\n};\n\n";

    //==6. GENERATE FINAL CODE==
    if(comments->isChecked()) generatedCode += classComments;
    if(protectHeaderMultipleInclusionCheckBox->isChecked()) generatedCode += inclusionProtectionBegin;

    generatedCode += beginDefClass
                     + publicMethods
                     + endDefClass;

    if(protectHeaderMultipleInclusionCheckBox->isChecked()) generatedCode += inclusionProtectionEnd;

    // CREATE A NEW WINDOW + DISPLAY GENERATED CODE
    GeneratedClassWindow generatedClassWindow(generatedCode, className);
    generatedClassWindow.exec();
}

void MainWindow::displayMissingClassNameError()
{
    QMessageBox::critical(this, tr("Erreur"), tr("Le nom de la classe n'a pas été renseigné !", "Message d'erreur pour nom de classe manquant"));
}
