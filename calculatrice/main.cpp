#include "calculatrice.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculatrice w;
    w.show();
    return a.exec();
}
