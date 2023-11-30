#include "ihm_tp1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM_TP1 w;
    w.show();
    return a.exec();
}
