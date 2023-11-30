#include "auditserveurmonowidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuditServeurMonoWidget w;
    w.show();
    return a.exec();
}
