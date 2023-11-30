#include "dialogconfigurerliaisongps.h"
#include "qserialport.h"
#include "ui_dialogconfigurerliaisongps.h"


DialogConfigurerLiaisonGPS::DialogConfigurerLiaisonGPS(QSerialPort &_lePort, QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogConfigurerLiaisonGPS),
    lePort(_lePort)
{
    int vitesse = 1200;
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);


    //Création des éléments de comboBoxPort
    for(const auto &info : QSerialPortInfo::availablePorts() ){
        qDebug() << info.portName();
        ui-> comboBoxPort ->addItem(info.portName());
    }

    //Création des éléments de comboBoxVitesse
    for(int i=0 ; i<8 ; i++){
        if(vitesse == 38400){
            ui-> comboBoxVitesse ->addItem(QString::number(vitesse));
            vitesse += 19200;
        }
        else{
            ui-> comboBoxVitesse ->addItem(QString::number(vitesse));
            vitesse = vitesse *2;
        }
    }




    ui->radioButtonNone -> isChecked();

    lePort.setStopBits(QSerialPort::OneStop);

    //Création des éléments de comboBoxFlux
    ui-> comboBoxFlux ->addItem("pas de contrôle de flux");
    ui-> comboBoxFlux ->addItem("Matériel (RTS/CTS)");
    ui-> comboBoxFlux ->addItem("logiciel (XON/XOFF)");

}



DialogConfigurerLiaisonGPS::~DialogConfigurerLiaisonGPS()
{
    delete ui;
}



void DialogConfigurerLiaisonGPS::on_comboBoxVitesse_currentTextChanged(const QString &arg1)
{
    lePort.setBaudRate(arg1.toInt());
}



void DialogConfigurerLiaisonGPS::on_comboBoxPort_currentTextChanged(const QString &arg1)
{
    if(ui-> comboBoxPort->currentText() != "Choisissez un port"){
        lePort.setPortName(ui->comboBoxPort->currentText());
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
    else{
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    }
}





void DialogConfigurerLiaisonGPS::on_radioButtonPaire_toggled(bool checked)
{
    if (checked == true){
        lePort.setParity(QSerialPort::EvenParity);
    }
}


void DialogConfigurerLiaisonGPS::on_radioButtonImpaire_toggled(bool checked)
{
    if (checked == true){
        lePort.setParity(QSerialPort::OddParity);
    }
}


void DialogConfigurerLiaisonGPS::on_radioButtonNone_toggled(bool checked)
{
    if (checked == true){
        lePort.setParity(QSerialPort::NoParity);
    }
}


void DialogConfigurerLiaisonGPS::on_checkBoxStop_toggled(bool checked)
{
    if (checked == false){
        lePort.setStopBits(QSerialPort::OneStop);
    }
    else{
        lePort.setStopBits(QSerialPort::TwoStop);
    }
}


void DialogConfigurerLiaisonGPS::on_spinBoxBitData_valueChanged(int arg1)
{
    switch(ui->spinBoxBitData->value()){

    case 8:
        lePort.setDataBits(QSerialPort::Data8);
        break;

    case 7:
        lePort.setDataBits(QSerialPort::Data7);
        break;

    case 6:
        lePort.setDataBits(QSerialPort::Data6);
        break;

    case 5:
        lePort.setDataBits(QSerialPort::Data5);
        break;

    default:
        break;
    }
}

