#include "widgetusb202.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetUSB202 w;
    w.show();
    return a.exec();
}
