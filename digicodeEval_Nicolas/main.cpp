#include "digicode.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    digicode w;
    w.show();
    return a.exec();
}
