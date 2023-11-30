#ifndef CALCULATRICESD_H
#define CALCULATRICESD_H

#include <QWidget>
#include <QJSEngine>



QT_BEGIN_NAMESPACE
namespace Ui { class Calculatricesd; }
QT_END_NAMESPACE

class Calculatricesd : public QWidget
{
    Q_OBJECT

public:
    Calculatricesd(QWidget *parent = nullptr);
    ~Calculatricesd();

private slots:
    void on_pushButtonClear_clicked();

    void on_pushButtonEgal_clicked();

    void onQPushButtonClicked();

private:
    Ui::Calculatricesd *ui;
};
#endif // CALCULATRICESD_H
