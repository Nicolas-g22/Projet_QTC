#include "widgetusb202.h"
#include "ui_widgetusb202.h"

WidgetUSB202::WidgetUSB202(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetUSB202)
{
    ui->setupUi(this);

    UlError erreur;
    erreur = laCarte.ulDConfigBit(LED1,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Config " << LED1 << " Code Erreur : " << erreur;
    erreur = laCarte.ulDConfigBit(LED2,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Config " << LED2 << " Code Erreur : " << erreur;


    connect(&timerBP,&QTimer::timeout,this,&WidgetUSB202::onTimerBP_timeOut);
    timerBP.start(500);

    UlError ulDConfigPort(const DigitalDirection _direction,const DigitalPortType _portType = AUXPORT);

    erreur = laCarte.ulDConfigBit(BP1,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Config " << BP1 << " Code Erreur : " << erreur;

    erreur = laCarte.ulDConfigBit(BP2,DD_OUTPUT);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Config " << BP2 << " Code Erreur : " << erreur;

}

WidgetUSB202::~WidgetUSB202()
{
    delete ui;
}



void WidgetUSB202::on_checkBox_LED1_stateChanged(int arg1)
{
    UlError erreur;
    erreur = laCarte.ulDBitOut(LED1,static_cast<bool>(arg1));
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Ecriture DIO" << LED1 << " Code Erreur : " << erreur;

}


void WidgetUSB202::on_checkBox_LED2_stateChanged(int arg1)
{
    UlError erreur;
    erreur = laCarte.ulDBitOut(LED2,static_cast<bool>(arg1));
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Ecriture DIO" << LED2 << " Code Erreur : " << erreur;

}

void WidgetUSB202::onTimerBP_timeOut()
{
    quint8 valeur;
    UlError erreur;
    erreur = laCarte.ulDIn(valeur);
    if(erreur != ERR_NO_ERROR)
        qDebug() << "Lecture port" << " Code Erreur : " << erreur;

    if(valeur & BP1)
        ui->label_BP1->setStyleSheet("background-color: rgb(255, 0, 0)");
    else
        ui->label_BP1->setStyleSheet("background-color: rgb(0, 255, 0)");


    if(valeur & BP2)
        ui->label_BP2->setStyleSheet("background-color: rgb(255, 0, 0)");
    else
        ui->label_BP2->setStyleSheet("background-color: rgb(0, 255, 0)");


}

