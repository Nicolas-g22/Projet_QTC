#include "digicode.h"
#include "ui_digicode.h"

digicode::digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::digicode)
{
    ui->setupUi(this);
}

digicode::~digicode()
{
    delete ui;
}

