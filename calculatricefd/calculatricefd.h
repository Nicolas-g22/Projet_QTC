#ifndef CALCULATRICEFD_H
#define CALCULATRICEFD_H

#include <QWidget>
#include <QJSEngine>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#define NBTOUCHES 16

QT_BEGIN_NAMESPACE
namespace Ui { class Calculatricefd; }
QT_END_NAMESPACE

class Calculatricefd : public QWidget
{
    Q_OBJECT

public:
    Calculatricefd(QWidget *parent = nullptr);
    ~Calculatricefd();
    const QString tableDesSymboles[NBTOUCHES]={"7", "8", "9", "+",
                                               "4", "5", "6", "-",
                                               "1", "2", "3", "*",
                                               "c", "0", "=", "/"};
    void onQPushButtonEgalclicked();
    void onQPushButtonClearclicked();
    QPushButton *touches[NBTOUCHES];
    QGridLayout *grille;
    QLineEdit *afficheur;
    void onQPushButtonClicked();

private:

    Ui::Calculatricefd *ui;
};
#endif // CALCULATRICEFD_H
