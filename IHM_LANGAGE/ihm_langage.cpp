#include "ihm_langage.h"
#include "ui_ihm_langage.h"

IHM_LANGAGE::IHM_LANGAGE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IHM_LANGAGE)
{
    ui->setupUi(this);
}

IHM_LANGAGE::~IHM_LANGAGE()
{
    delete ui;
}


void IHM_LANGAGE::on_pushButtonLinux_3_clicked()
{
    ui -> textEditEvenement -> append("Bouton Linux");
}


void IHM_LANGAGE::on_pushButtonWindows_3_clicked()
{
    ui -> textEditEvenement -> append("Bouton Windows");
}


void IHM_LANGAGE::on_pushButtonLion_3_clicked()
{
    ui -> textEditEvenement -> append("Bouton OS X Lion");
}


void IHM_LANGAGE::on_checkBoxLinux_3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        ui -> textEditEvenement -> append("Linux Coche");
    }
    else{
        ui -> textEditEvenement -> append("Linux Décoche");
    }
}


void IHM_LANGAGE::on_checkBoxWindows_3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        ui -> textEditEvenement -> append("Windows Coche");
    }
    else{
        ui -> textEditEvenement -> append("Windows Décoche");
    }
}


void IHM_LANGAGE::on_checkBoxLion_3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        ui -> textEditEvenement -> append("OS X Lion Coche");
    }
    else{
        ui -> textEditEvenement -> append("OS X Lion Décoche");
    }
}


void IHM_LANGAGE::on_radioButtonLinux__clicked()
{
    ui -> textEditEvenement -> append("Linux Radio");
}


void IHM_LANGAGE::on_radioButtonWindows_3_clicked()
{
    ui -> textEditEvenement -> append("Windows Radio");
}


void IHM_LANGAGE::on_radioButtonLion_3_clicked()
{
    ui -> textEditEvenement -> append("OS X Lion Radio");
}


void IHM_LANGAGE::on_comboBoxChoix_3_currentTextChanged(const QString &arg1)
{
    ui -> textEditEvenement -> append(arg1);
}


void IHM_LANGAGE::on_lineEditEntrezCode_3_textChanged(const QString &arg1)
{
    ui -> textEditEvenement -> append(arg1);
}


void IHM_LANGAGE::on_actionC_2_triggered()
{
    ui -> textEditEvenement -> append("C");
}


void IHM_LANGAGE::on_actionJava_triggered()
{
    ui -> textEditEvenement -> append("Java");
}


void IHM_LANGAGE::on_actionC_3_triggered()
{
    ui -> textEditEvenement -> append("C++");
}


void IHM_LANGAGE::on_actionPHP_triggered()
{
    ui -> textEditEvenement -> append("PHP");
}


void IHM_LANGAGE::on_actionJavaScript_triggered()
{
    ui -> textEditEvenement -> append("Java Script");
}

