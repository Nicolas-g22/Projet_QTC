#include "equilibreuse.h"
#include "rapportmesures.h"
#include "ui_equilibreuse.h"

#include "dialogparametrageequilibreuse.h"

#include <QFileInfo>
#include <QSettings>
#include <QFileDialog>

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
    , experience(nullptr)
    , vueGraphique(nullptr)
    , chartView(nullptr)
{
    ui->setupUi(this);

    layout = new QHBoxLayout(ui->widgetCourbes);
    ChangerEtatSysteme(REPOS);

}

Equilibreuse::~Equilibreuse()
{
    delete ui;
}


void Equilibreuse::on_actionParametrer_triggered()
{
    if(experience != nullptr)
    {
        DialogParametrageEquilibreuse dlgParametrage(experience,this);
        dlgParametrage.exec();
    }
}

void Equilibreuse::on_actionNouvelle_Experience_triggered()
{
    if(experience !=nullptr)
        delete experience;
    experience = new Experience;
}

void Equilibreuse::on_actionImporter_mesures_brutes_triggered()
{
    if(experience != nullptr)
        delete experience;
    experience = new Experience(this);

    QString leFichier;

    // ouverture de la boite de dialogue TD2
    leFichier = QFileDialog::getOpenFileName(this, "Fichier mesures brutes", "", "fichier mesures brutes(*.mbr)");

    if (!leFichier.isEmpty())
    {
        experience->LireMesuresBrutes(leFichier);
        experience->InitiliserCourbes();
        MettreAjourCourbe();
        MettreAjourTableauAcquisition();
        MettreAjourVitesseExperience();

        ChangerEtatSysteme(RESTITUTION);
    }

}

void Equilibreuse::ChangerEtatSysteme(Equilibreuse::ETAT_SYSTEME etat)
{
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::black);
    labelEtatCapot.setPalette(palette);
    etatDuSysteme = etat;
    switch(etatDuSysteme)
    {
    case REPOS:
        ui->groupBoxVitesse->setVisible(false);
        ui->groupeBoxAcquisition->setDisabled(true);
        ui->groupeBoxConsigneVitesse->setDisabled(true);
        ui->groupeBoxOrigine->setDisabled(true);
        ui->buttonArretMoteur->setDisabled(true);
        ui->buttonLancerMoteur->setEnabled(true);
        ui->actionEnregistrer->setDisabled(true);
        ui->menuExporter->setDisabled(true);
        labelEtatSysteme.setText("| Repos ");
        break;
    case PRISE_ORIGINE:
        ui->groupeBoxOrigine->setEnabled(true);
        labelEtatSysteme.setText("| Prise de l'origine ");
        break;
    case ATTENTE_CONSIGNE_VITESSE:
        ui->groupeBoxOrigine->setDisabled(true);
        ui->groupeBoxConsigneVitesse->setEnabled(true);
        ui->groupeBoxAcquisition->setDisabled(true);
        ui->buttonLancerMoteur->setEnabled(true);
        labelEtatSysteme.setText("| Attente consigne vitesse ");
        break;
    case EN_ROTATION:
        ui->buttonArretMoteur->setEnabled(true);
        ui->buttonLancerAcquisition->setEnabled(true);
        ui->groupeBoxAcquisition->setEnabled(true);
        ui->groupBoxVitesse->setVisible(false);
        labelEtatSysteme.setText("| En rotation ");
        break;
    case SECURITE:
        ui->buttonLancerAcquisition->setDisabled(true);
        ui->buttonArretMoteur->setDisabled(true);
        ui->buttonLancerMoteur->setDisabled(true);
        labelEtatSysteme.setText("| Sécurité ");
        break;
    case EXPERIENCE_FIGEE:
        ui->groupBoxVitesse->setVisible(true);
        labelEtatSysteme.setText("| Expérience figée ");
        break;
    case RESTITUTION:
        ui->groupeBoxOrigine->setDisabled(true);
        ui->groupeBoxConsigneVitesse->setDisabled(true);
        ui->buttonLancerAcquisition->setDisabled(true);
        ui->groupeBoxAcquisition->setEnabled(true);
        ui->groupBoxVitesse->setVisible(true);
        ui->menuExporter->setEnabled(true);
        ui->actionEnregistrer->setEnabled(true);
        labelEtatSysteme.setText("| Mode restitution ");
        break;
    default:
        labelEtatSysteme.setText("| non défini ");
        break;
    }
}

void Equilibreuse::MettreAjourCourbe()
{
    if(experience != nullptr)
    {
        if(vueGraphique != nullptr)
            delete vueGraphique;
        vueGraphique = new VueGraphique(experience);
        if(chartView != nullptr)
        {
            delete chartView;
        }
        chartView = new QChartView(vueGraphique->DessinerCourbes());

        layout->addWidget(chartView);
    }
}

/**
 * @brief Equilibreuse::MettreAjourTableauAcquisition
 * @details Affiche le tableau d'acquisition à partir des données de l'expérience.
 *          Elle deux courbes doivent-être initialisée ou chargée.
 */
void Equilibreuse::MettreAjourTableauAcquisition()
{
    if(experience != nullptr)
    {
        QPointF point;
        point = experience->RechercherEffortMax('A');
        ui->tableWidgetAcquisition->item(0,0)->setText(QString::number(point.y(),'f',1));
        ui->tableWidgetAcquisition->item(0,1)->setText(QString::number(point.x(),'f',0));
        point = experience->RechercherEffortMax('O');
        ui->tableWidgetAcquisition->item(1,0)->setText(QString::number(point.y(),'f',1));
        ui->tableWidgetAcquisition->item(1,1)->setText(QString::number(point.x(),'f',0));
        double valeur;
        valeur = experience->RechercherEffortAzero('A');
        ui->tableWidgetAcquisition->item(0,2)->setText(QString::number(valeur,'f',1));
        valeur = experience->RechercherEffortAzero('O');
        ui->tableWidgetAcquisition->item(1,2)->setText(QString::number(valeur,'f',1));
        valeur = experience->RechercherEffortAquatreVingtDix('A');
        ui->tableWidgetAcquisition->item(0,3)->setText(QString::number(valeur,'f',1));
        valeur = experience->RechercherEffortAquatreVingtDix('O');
        ui->tableWidgetAcquisition->item(1,3)->setText(QString::number(valeur,'f',1));
    }
}

/**
 * @brief Equilibreuse::MettreAjourVitesseExperience
 * @details Affiche la vitesse de l'expérience
 */
void Equilibreuse::MettreAjourVitesseExperience()
{
    if(experience != nullptr)
    {
        qint16 vitesseExperience = experience->ObtenirVitesse();
        ui->lineEditVitesseExperience->setText(QString::number(vitesseExperience));
    }
}

void Equilibreuse::on_actionFormat_PDF_triggered()
{
    // ouverture de la boite de dialogue

    if(experience != nullptr)
    {
        QString leFichier = QFileDialog::getSaveFileName(this,"ecriture fichier pdf" "", (".pdf"));
        if(!leFichier.isEmpty())
        {
            RapportMesures leRapport(*experience,*chartView,leFichier);
            leRapport.ConstruireRapport();
        }
    }
}

