#include "ihm_digicode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM_Digicode w;
    w.show();
    return a.exec();
}
