#ifndef DIGICODE_H
#define DIGICODE_H

#include <QWidget>
#include <QJSEngine>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#define NBTOUCHES 12

QT_BEGIN_NAMESPACE
namespace Ui { class digicode; }
QT_END_NAMESPACE

class digicode : public QWidget
{
    Q_OBJECT

public:
    digicode(QWidget *parent = nullptr);
    ~digicode();
    const QString tableDesSymboles[NBTOUCHES]={"7", "8", "9",
                                               "4", "5", "6",
                                               "1", "2", "3",
                                               "On", "0", "Ok"};
    void onQPushButtonOnclicked();
    void onQPushButtonOkclicked();

private:
    Ui::digicode *ui;
};
#endif // DIGICODE_H
