#include "ihm_tp1.h"
#include "ui_ihm_tp1.h"

IHM_TP1::IHM_TP1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM_TP1)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1, false);

}

IHM_TP1::~IHM_TP1()
{
    delete ui;
}


void IHM_TP1::on_pushButtonSuite_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->widget(1)->setVisible(true);
    ui->tabWidget->setTabEnabled(1, true);

    afficherInfos();
}

void IHM_TP1::afficherInfos()
{
    // Initialisation variables
    double imcs[NBIMC] = {16.5, 18.5, 25, 30, 35, 40};
    QString corpulences[NBCORPULENCE] = {"Famine", "Maigreur", "Normale", "Surpoids", "Obésité modérée", "Obésité sévère", "Obésité morbide"};
    double imc=0;

    // initialisation de poids, taille, âge, nom et prenom
    QString nom=ui->lineEditNom->text();
    QString prenom=ui->lineEditPrenom->text();
    age = ui ->spinBoxAge->value();
    poids = ui -> doubleSpinBoxPoids->value();
    taille = ui -> doubleSpinBoxTaille -> value();

    // affichage message de bienvenue
    ui -> textEditAfficheur -> append("Bonjour " + nom + " " + prenom);

    // calcul de l'imc
    imc = poids/(taille*taille);

    // affichage de l'imc
    ui->textEditAfficheur->append("Votre indice de masse corporel est de : " +QString::number(imc));
    int indiceCorpulence = 0;
    for (int i = 0; i < NBIMC - 1; i++) {
        if (imc > imcs[i] && imc <= imcs[i + 1]) {
            indiceCorpulence = i + 1;
        }
    }

    // cas extreme
    if (imc < 16.5) {
        indiceCorpulence = 0;
    }
    if (imc > 40) {
       indiceCorpulence = NBCORPULENCE - 1;
    }

    // affichage de la corpulence: corpulences[indiceCorpulence]
    ui -> textEditAfficheur -> append("Votre indice de corpulance est : " + corpulences[indiceCorpulence]);
}


void IHM_TP1::on_pushButtonDevine_clicked()
{
    double poidsIdeal = 0;
    if (ui->radioButtonFemme->isChecked()) {
        poidsIdeal = 45.5 + 2.3 * (taille / 0.0254 - 60.0);
    }
    if (ui->radioButtonHomme->isChecked()) {
        poidsIdeal = 50.0 + 2.3 * (taille / 0.0254 - 60.0);
    }
    if (poidsIdeal > 0) {
        ui->textEditAfficheur->append("\nVotre poids ideal avec la formule de devine : " + QString::number(poidsIdeal) + " kg\n");
        double ecart = poids-poidsIdeal;
        if (ecart >= 0) {
          ui->textEditAfficheur->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
        }
        else {
          ui->textEditAfficheur->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
        }
    }
}


void IHM_TP1::on_pushButtonLorentz_clicked()
{
    double poidsIdeal = 0;
    if (ui->radioButtonFemme->isChecked()) {
        poidsIdeal = taille * 100 - 100 - (taille*100-150)/2.5;
    }
    if (ui->radioButtonHomme->isChecked()) {
        poidsIdeal = taille * 100 - 100 - (taille*100-150)/4;
    }
    if (poidsIdeal > 0) {
        ui->textEditAfficheur->append("\nVotre poids ideal avec la formule de Lorentz (en tenant compte du sexe) : " + QString::number(poidsIdeal) + " kg\n");
        double ecart = poids-poidsIdeal;
        if (ecart >= 0) {
          ui->textEditAfficheur->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
        }
        else {
          ui->textEditAfficheur->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
        }
    }
}


void IHM_TP1::on_pushButtonFonctionAge_clicked()
{
    double poidsIdeal = 0;

    poidsIdeal = 50+(taille*100-150)/4.0+(age-20)/4.0;

    if (poidsIdeal > 0) {
        ui->textEditAfficheur->append("\nVotre poids ideal avec la formule de Lorentz (en tenant compte de l'age) : " + QString::number(poidsIdeal) + " kg\n");
        double ecart = poids-poidsIdeal;
        if (ecart >= 0) {
          ui->textEditAfficheur->append("\nVous devez perdre "+QString::number(ecart)+" kg\n");
        }
        else {
          ui->textEditAfficheur->append("\nVous devez prendre "+QString::number(-ecart)+" kg\n");
        }
    }
}

