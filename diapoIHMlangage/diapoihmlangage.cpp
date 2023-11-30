#include "diapoihmlangage.h"
#include "ui_diapoihmlangage.h"

DiapoIHMlangage::DiapoIHMlangage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DiapoIHMlangage)
{
    ui->setupUi(this);
}

DiapoIHMlangage::~DiapoIHMlangage()
{
    delete ui;
}

