#ifndef DIALOGCONFIGURERLIAISONGPS_H
#define DIALOGCONFIGURERLIAISONGPS_H
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QPushButton>
namespace Ui {
class DialogConfigurerLiaisonGPS;
}

class DialogConfigurerLiaisonGPS : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigurerLiaisonGPS(QSerialPort &_lePort, QWidget *parent = nullptr);
    ~DialogConfigurerLiaisonGPS();




protected:
    Ui::DialogConfigurerLiaisonGPS *ui;
    QSerialPort &lePort;

private slots:
    void on_comboBoxPort_currentTextChanged(const QString &arg1);
    void on_comboBoxVitesse_currentTextChanged(const QString &arg1);
    void on_radioButtonPaire_toggled(bool checked);
    void on_radioButtonImpaire_toggled(bool checked);
    void on_radioButtonNone_toggled(bool checked);

    void on_checkBoxStop_toggled(bool checked);
    void on_spinBoxBitData_valueChanged(int arg1);
};

#endif // DIALOGCONFIGURERLIAISONGPS_H
