#include "calculatriceip.h"
#include "ui_calculatriceip.h"

CalculatriceIP::CalculatriceIP(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceIP)
{
    ui->setupUi(this);
    char i;
    for(i=8;i<31;i++){
        ui -> comboBoxSufixe -> addItem(QString::number(i));
    }

}

CalculatriceIP::~CalculatriceIP()
{
    delete ui;
}

void CalculatriceIP::on_pushButtonQuitter_clicked()
{

}


void CalculatriceIP::on_comboBoxSufixe_currentIndexChanged(int index)
{

}

