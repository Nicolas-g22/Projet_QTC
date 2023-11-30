#include "calculatrice.h"
#include "ui_calculatrice.h"

Calculatrice::Calculatrice(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatrice)
{
    ui->setupUi(this);
}

Calculatrice::~Calculatrice()
{
    delete ui;
}


void Calculatrice::on_pushButton1_clicked()
{
    ui -> lineEditAfficheur -> insert("1");
}


void Calculatrice::on_pushButton2_clicked()
{
    ui -> lineEditAfficheur -> insert("2");
}


void Calculatrice::on_pushButton3_clicked()
{
    ui -> lineEditAfficheur -> insert("3");
}


void Calculatrice::on_pushButtonMultiplier_clicked()
{
    ui -> lineEditAfficheur -> insert("*");
}


void Calculatrice::on_pushButton0_clicked()
{
    ui -> lineEditAfficheur -> insert("0");
}


void Calculatrice::on_pushButtonClear_clicked()
{
    ui -> lineEditAfficheur -> setText(" ");
}


void Calculatrice::on_pushButtonDiviser_clicked()
{
    ui -> lineEditAfficheur -> insert("/");
}


void Calculatrice::on_pushButtonMoins_clicked()
{
    ui -> lineEditAfficheur -> insert("-");
}


void Calculatrice::on_pushButton6_clicked()
{
    ui -> lineEditAfficheur -> insert("6");
}


void Calculatrice::on_pushButton5_clicked()
{
    ui -> lineEditAfficheur -> insert("5");
}


void Calculatrice::on_pushButton4_clicked()
{
    ui -> lineEditAfficheur -> insert("4");
}


void Calculatrice::on_pushButton7_clicked()
{
    ui -> lineEditAfficheur -> insert("7");
}


void Calculatrice::on_pushButton8_clicked()
{
    ui -> lineEditAfficheur -> insert("8");
}


void Calculatrice::on_pushButton9_clicked()
{
    ui -> lineEditAfficheur -> insert("9");
}


void Calculatrice::on_pushButtonPlus_clicked()
{
    ui -> lineEditAfficheur -> insert("+");
}


void Calculatrice::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue resultat;
    QString afficheur;

    afficheur = ui -> lineEditAfficheur -> text();

    resultat = myEngine.evaluate(afficheur);

    ui -> lineEditAfficheur -> setText(resultat.toString());
}

