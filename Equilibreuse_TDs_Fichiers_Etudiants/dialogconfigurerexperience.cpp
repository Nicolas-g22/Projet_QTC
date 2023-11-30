#include "dialogconfigurerexperience.h"
#include "ui_dialogconfigurerexperience.h"

DialogConfigurerExperience::DialogConfigurerExperience(Experience *_experience, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigurerExperience),
    experience(_experience)
{
    ui->setupUi(this);
    QDate date;
    date = QDate::currentDate();
    ui->dateEdit->setDate(date);

    if(experience != nullptr)
    {
        ui->lineEditLieu->setText(experience->ObtenirEtablissement());
        ui->lineEditNometudiant->setText(experience->ObtenirNom());
        ui->lineEditPrenomEtudiant->setText(experience->ObtenirPrenom());
        ui->lineEditClasse->setText(experience->ObtenirClasse());
        ui->textEditCommentaire->setText(experience->ObtenirCommentaire());
        //ui->dateEdit->setDate(experience.ObtenirDate().fromStdString());
    }
}

DialogConfigurerExperience::~DialogConfigurerExperience()
{
    delete ui;
}

void DialogConfigurerExperience::on_pushButtonValider_clicked()
{

    experience->ModifierDate(ui->dateEdit->date());
    experience->ModifierNom(ui->lineEditNometudiant->text());
    experience->ModifierPrenom(ui->lineEditPrenomEtudiant->text());
    experience->ModifierClasse(ui->lineEditClasse->text());
    experience->ModifierEtablissement(ui->lineEditLieu->text());
    experience->ModifierCommentaire(ui->textEditCommentaire->toPlainText());
    experience->ValiderConfig(true);
    close();
}

void DialogConfigurerExperience::on_pushButtonAnnuler_clicked()
{
    experience->ValiderConfig(false);
    close();
}
