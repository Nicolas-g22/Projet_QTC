#include "auditserveurmultiwidget.h"
#include "ui_auditserveurmultiwidget.h"

AuditServeurMultiWidget::AuditServeurMultiWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuditServeurMultiWidget)
{
    ui->setupUi(this);
}

AuditServeurMultiWidget::~AuditServeurMultiWidget()
{
    delete ui;
}

