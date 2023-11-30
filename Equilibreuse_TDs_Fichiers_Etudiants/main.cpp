#include "equilibreuse.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Equilibreuse ihm;
    ihm.show();
    return a.exec();
}
