#ifndef CALCULATRICEIP_H
#define CALCULATRICEIP_H

#include <QWidget>
#include <QWidget>

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class CalculatriceIP; }
QT_END_NAMESPACE

class CalculatriceIP : public QWidget
{
    Q_OBJECT

public:
    CalculatriceIP(QWidget *parent = nullptr);
    ~CalculatriceIP();

private slots:
    void on_pushButtonQuitter_clicked();

    void on_comboBoxSufixe_currentIndexChanged(int index);

private:
    Ui::CalculatriceIP *ui;
};
#endif // CALCULATRICEIP_H
