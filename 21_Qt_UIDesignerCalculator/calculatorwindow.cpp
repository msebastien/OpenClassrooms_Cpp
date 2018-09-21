#include "calculatorwindow.h"
#include "ui_calculatorwindow.h"

CalculatorWindow::CalculatorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculatorWindow)
{
    ui->setupUi(this);

    // EVENTS
    connect(ui->getResultButton, SIGNAL(clicked()), this, SLOT(computeResult()));
}

CalculatorWindow::~CalculatorWindow()
{
    delete ui;
}

void CalculatorWindow::computeResult()
{
    if(ui->operatorComboBox->currentText() == "+")
    {
        ui->resultLabel->setNum(ui->operand1_spinBox->value() + ui->operand2_spinBox->value());
    }
    else if(ui->operatorComboBox->currentText() == "-")
    {
        ui->resultLabel->setNum(ui->operand1_spinBox->value() - ui->operand2_spinBox->value());
    }
    else if(ui->operatorComboBox->currentText() == "*")
    {
        ui->resultLabel->setNum(ui->operand1_spinBox->value() * ui->operand2_spinBox->value());
    }
    else if(ui->operatorComboBox->currentText() == "/")
    {
        if(ui->operand2_spinBox->value() != 0)
        {
            double result = (double)ui->operand1_spinBox->value() / (double)ui->operand2_spinBox->value();
            ui->resultLabel->setText(QString::number(result));
        }
        else
        {
            ui->resultLabel->setText("Erreur");
            QMessageBox::critical(this, "Erreur", "Il est impossible de diviser par zéro.");
        }

    }


}
