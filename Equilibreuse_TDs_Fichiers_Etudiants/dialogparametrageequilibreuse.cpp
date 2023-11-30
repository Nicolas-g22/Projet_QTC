#include "dialogparametrageequilibreuse.h"
#include "ui_dialogparametrageequilibreuse.h"
#include "constante.h"
#include "equilibreuse.h"

DialogParametrageEquilibreuse::DialogParametrageEquilibreuse(Experience *_experience, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogParametrageEquilibreuse),
    experience(_experience)

{
    ui->setupUi(this);

    ui->tableWidgetJauges->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetJauges->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetConditionneur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetConditionneur->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetFiltre->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetFiltre->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    AfficherConfiguration();
}

DialogParametrageEquilibreuse::~DialogParametrageEquilibreuse()
{
    delete ui;
}

void DialogParametrageEquilibreuse::AfficherConfiguration()
{
    paliers = experience->ObtenirCarateristiquesPaliers();
    QString texte;
    ui->tableWidgetJauges->setItem (PALIER_A,0,new QTableWidgetItem(paliers[PALIER_A].jauge.modele));
    ui->tableWidgetJauges->setItem(PALIER_A,1,new QTableWidgetItem(paliers[PALIER_A].jauge.date));
    ui->tableWidgetJauges->setItem(PALIER_A,2,new QTableWidgetItem(paliers[PALIER_A].jauge.numeroDeSerie));
    texte = QString::number(paliers[PALIER_A].jauge.capacite,'f',0);
    ui->tableWidgetJauges->setItem(PALIER_A,3,new QTableWidgetItem(texte));
    texte = QString::number(paliers[PALIER_A].jauge.sensibilite,'f',3);
    ui->tableWidgetJauges->setItem(PALIER_A,4,new QTableWidgetItem(texte));

    ui->tableWidgetJauges->setItem (PALIER_O,0,new QTableWidgetItem(paliers[PALIER_O].jauge.modele));
    ui->tableWidgetJauges->setItem(PALIER_O,1,new QTableWidgetItem(paliers[PALIER_O].jauge.date));
    ui->tableWidgetJauges->setItem(PALIER_O,2,new QTableWidgetItem(paliers[PALIER_O].jauge.numeroDeSerie));
    texte = QString::number(paliers[PALIER_O].jauge.capacite,'f',0);
    ui->tableWidgetJauges->setItem(PALIER_O,3,new QTableWidgetItem(texte));
    texte = QString::number(paliers[PALIER_O].jauge.sensibilite,'f',3);
    ui->tableWidgetJauges->setItem(PALIER_O,4,new QTableWidgetItem(texte));


    for (int i= 0;i < 5 ;i++ ) {
        ui->tableWidgetJauges->item(PALIER_A,i)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetJauges->item(PALIER_O,i)->setTextAlignment(Qt::AlignCenter);
    }
}

void DialogParametrageEquilibreuse::on_pushButtonEnregistrer_clicked()
{
    paliers[PALIER_A].jauge.modele = ui->tableWidgetJauges->item(PALIER_A,0)->text();
    paliers[PALIER_O].jauge.modele = ui->tableWidgetJauges->item(PALIER_O,0)->text();
    paliers[PALIER_A].jauge.date = ui->tableWidgetJauges->item(PALIER_A,1)->text();
    paliers[PALIER_O].jauge.date = ui->tableWidgetJauges->item(PALIER_O,1)->text();
    paliers[PALIER_A].jauge.numeroDeSerie = ui->tableWidgetJauges->item(PALIER_A,2)->text();
    paliers[PALIER_O].jauge.numeroDeSerie = ui->tableWidgetJauges->item(PALIER_O,2)->text();
    paliers[PALIER_A].jauge.capacite = ui->tableWidgetJauges->item(PALIER_A,3)->text().toDouble();
    paliers[PALIER_O].jauge.capacite = ui->tableWidgetJauges->item(PALIER_O,3)->text().toDouble();
    paliers[PALIER_A].jauge.sensibilite = ui->tableWidgetJauges->item(PALIER_A,4)->text().toDouble();
    paliers[PALIER_O].jauge.sensibilite = ui->tableWidgetJauges->item(PALIER_O,4)->text().toDouble();

    experience->EnregistreFichierIni(paliers);

}
