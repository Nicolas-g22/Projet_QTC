#include "ihm_langage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM_LANGAGE w;
    w.show();
    return a.exec();
}
