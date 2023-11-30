#include "widget.h"
#include "ui_widget.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(const auto &info : QSerialPortInfo::availablePorts() ){
        qDebug() << info.portName();
        ui->comboBox ->addItem(info.portName());
        connect(&lePort, &QSerialPort::readyRead, this, &Widget::onQSerialPort_readyRead);

    }
}
Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(ui->pushButton->text()== "Fermer le port"){
        ui->pushButton->setText("Ouvrir le port Serie");
    }
    else{
        ui->pushButton->setText("Fermer le port");
        if (ui->comboBox->currentIndex() != 0){
            lePort.setPortName(ui->comboBox->currentText());
            lePort.setBaudRate(QSerialPort::Baud115200);
            lePort.setDataBits(QSerialPort::Data8);
            lePort.setParity(QSerialPort::NoParity);
            lePort.setStopBits(QSerialPort::OneStop);
            if(lePort.open(QIODevice::ReadWrite)){
                qDebug() << "Le port série est ouvert";

            }
            else{
                QMessageBox erreur;
                erreur.setText("Veuillez sélectionnez un port");
                erreur.exec();
            }
        }
    }
}

void Widget::onQSerialPort_readyRead()
{
    qDebug() << "in slot";
    QByteArray response;
    response=lePort.readAll();
    ui->textEdit->append(response);

}



void Widget::on_pushButton_2_clicked()
{
    QString texte;
    texte = ui->lineEdit->text();
    lePort.write(texte.toLatin1());
}

