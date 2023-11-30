#include "bdd_td1.h"
#include "ui_bdd_td1.h"

BDD_TD1::BDD_TD1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BDD_TD1)
{
    ui->setupUi(this);
    bdd = QSqlDatabase::addDatabase("QMYSQL");
    bdd.setHostName("172.18.58.7");
    bdd.setDatabaseName("france2018");
    bdd.setUserName("snir");
    bdd.setPassword("snir");

    if(!bdd.open()){
        QMessageBox::warning(this, "Erreur de connexion à la bdd", bdd.lastError().text());

    }
    else{
        qDebug() << "Ouverture de la BDD" << bdd.databaseName();
    }

    QSqlQuery requete("select code, name from regions order by name;" );
    if (!requete.exec()){
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nom;
    QString id;

    while(requete.next())
    {
        nom=requete.value("name").toString();
        id=requete.value("code").toString();
        ui->comboBoxRegions->addItem(nom,id);
    }
}



void BDD_TD1::on_pushButton_clicked()
{
    QSqlQuery requetePrepare;
    requetePrepare.prepare("SELECT name FROM departments WHERE code=:idr;");
    requetePrepare.bindValue(":idr", ui->lineEdit->text().toInt());
    if(!requetePrepare.exec()){
        qDebug() << "Probleme requete" << requetePrepare.lastError().text();

    }

    int nbLignes = requetePrepare.size();
    qDebug()<<"name :"<< nbLignes;

    if(requetePrepare.next()){
        QString nomDepartement;
        nomDepartement=requetePrepare.value("name").toString();
        ui->label_2->setText(nomDepartement);
    }



}


BDD_TD1::~BDD_TD1()
{
    delete ui;
}

void BDD_TD1::on_comboBoxRegions_currentIndexChanged(int index)
{
    // recupere l'id de la region
    QString idRegion=ui->comboBoxRegions->itemData(index).toString();
    // vider la liste des departements
    ui->comboBoxDepartements->clear();
    ui->comboBoxDepartements->addItem("Choisissez un département");

    QSqlQuery requete;
    requete.prepare("select name, code from departments  where region_code=:idr order by name;" );
    requete.bindValue(":idr", idRegion);

    if (!requete.exec()){
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nom;
    QString id;

    while(requete.next())
    {
        nom=requete.value("name").toString();
        id=requete.value("code").toString();
        ui->comboBoxDepartements->addItem(nom,id);
    }
}



void BDD_TD1::on_comboBoxDepartements_currentIndexChanged(int index)
{
    // recupere l'id de la region
    QString idDepartments=ui->comboBoxDepartements->itemData(index).toString();
    // vider la liste des departements
    ui->comboBoxVilles->clear();
    ui->comboBoxVilles->addItem("Choisissez une ville");

    QSqlQuery requete;
    requete.prepare("select name, zip_code from cities  where department_code=:idr order by name;" );
    requete.bindValue(":idr", idDepartments);

    if (!requete.exec()){
        qDebug()<<"pb requete "<<requete.lastError();
    }
    QString nom;
    QString id;

    while(requete.next())
    {
        nom=requete.value("name").toString();
        id=requete.value("zip_code").toString();
        ui->comboBoxVilles->addItem(nom,id);
    }
}


