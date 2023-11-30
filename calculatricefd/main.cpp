#include "calculatricefd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculatricefd w;
    w.show();
    return a.exec();
}
