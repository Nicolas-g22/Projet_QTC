#ifndef INTERFACEPRINCIPALE_H
#define INTERFACEPRINCIPALE_H

#include "qlabel.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include <dialogconfigurerliaisongps.h>
#include <QTime>
#include <QDate>
#include <QTimeZone>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class InterfacePrincipale; }
QT_END_NAMESPACE

class InterfacePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    InterfacePrincipale(QWidget *parent = nullptr);
    ~InterfacePrincipale();
    void DecodageNMEA(const QString &_trameNMEA);

protected slots:
    void on_actionConfigurer_triggered();
    void onQserialPort_ReadyRead();


protected:
    Ui::InterfacePrincipale *ui;
    QLabel labelEtatPort;
    QByteArray buffer;
    QSerialPort lePort;
    DialogConfigurerLiaisonGPS configGPS;
private slots:
    void on_actionEnregistrer_triggered();
};

#endif // INTERFACEPRINCIPALE_H
