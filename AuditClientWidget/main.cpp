#include "auditclientwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuditClientWidget w;
    w.show();
    return a.exec();
}
