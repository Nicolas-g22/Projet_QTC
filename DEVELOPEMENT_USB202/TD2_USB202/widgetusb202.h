#ifndef WIDGETUSB202_H
#define WIDGETUSB202_H

#include <QWidget>
#include "mcculdaq.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetUSB202; }

QT_END_NAMESPACE

class WidgetUSB202 : public QWidget
{
    Q_OBJECT

public:
    WidgetUSB202(QWidget *parent = nullptr);
    ~WidgetUSB202();

private slots:
    void on_checkBox_LED1_stateChanged(int arg1);

    void on_checkBox_LED2_stateChanged(int arg1);

    void onTimerBP_timeOut();

private:
    Ui::WidgetUSB202 *ui;
    MccUldaq laCarte;
    QTimer timerBP;
};
#endif // WIDGETUSB202_H

enum LED{
  LED1 = 7,
  LED2 = 6
};

enum BP{
  BP1 = 0,
  BP2 = 1
};
