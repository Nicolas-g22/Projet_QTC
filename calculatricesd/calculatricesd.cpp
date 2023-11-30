#include "calculatricesd.h"
#include "ui_calculatricesd.h"

Calculatricesd::Calculatricesd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatricesd)
{
    ui->setupUi(this);

    connect(ui->pushButton0, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton1, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton2, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton3, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton4, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton5, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton6, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton7, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton8, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButton9, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButtonMultiplier, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButtonPlus, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButtonMoins, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);
    connect(ui->pushButtonDiviser, &QPushButton::clicked, this , &Calculatricesd::onQPushButtonClicked);

}

Calculatricesd::~Calculatricesd()
{
    delete ui;
}


void Calculatricesd::on_pushButtonClear_clicked()
{
    ui -> lineEditAfficheur -> setText(" ");

}


void Calculatricesd::on_pushButtonEgal_clicked()
{
    QJSEngine myEngine;
    QJSValue resultat;
    QString afficheur;

    afficheur = ui -> lineEditAfficheur -> text();

    resultat = myEngine.evaluate(afficheur);

    ui -> lineEditAfficheur -> setText(resultat.toString());
}

void Calculatricesd::onQPushButtonClicked(){
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString val = touche->text();
    ui -> lineEditAfficheur -> insert(val);
}
