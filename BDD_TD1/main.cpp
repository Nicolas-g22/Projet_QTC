#include "bdd_td1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD_TD1 w;
    w.show();
    return a.exec();
}
