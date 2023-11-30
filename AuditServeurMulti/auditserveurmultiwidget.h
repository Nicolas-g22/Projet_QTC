#ifndef AUDITSERVEURMULTIWIDGET_H
#define AUDITSERVEURMULTIWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AuditServeurMultiWidget; }
QT_END_NAMESPACE

class AuditServeurMultiWidget : public QWidget
{
    Q_OBJECT

public:
    AuditServeurMultiWidget(QWidget *parent = nullptr);
    ~AuditServeurMultiWidget();

private:
    Ui::AuditServeurMultiWidget *ui;
};
#endif // AUDITSERVEURMULTIWIDGET_H
