#include "webserveurwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WebServeurWidget w;
    w.show();
    return a.exec();
}
