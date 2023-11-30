#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QtCharts>

#include "experience.h"
#include "vuegraphique.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();

private slots:
    void on_actionParametrer_triggered();
    void on_actionNouvelle_Experience_triggered();

    void on_actionImporter_mesures_brutes_triggered();


    void on_actionFormat_PDF_triggered();

private:

    enum ETAT_SYSTEME       /// Résume les etats possibles du système
    {
        REPOS,
        PRISE_ORIGINE,
        ATTENTE_CONSIGNE_VITESSE,
        EN_ROTATION,
        ACQUISITION,
        SECURITE,
        RESTITUTION,
        EXPERIENCE_FIGEE
    };

    void ChangerEtatSysteme(ETAT_SYSTEME etat);
    void MettreAjourCourbe();
    void MettreAjourTableauAcquisition();
    void MettreAjourVitesseExperience();


    Ui::Equilibreuse *ui;
    Experience *experience;
    VueGraphique *vueGraphique; /// pointeur vers la représentation graphique de l'expérience
    ETAT_SYSTEME etatDuSysteme; /// Mémorise l'état du système (automate d'état)

    QLabel labelEtatCapot;      /// Affichage de l'état du capot (ouvert ou fermé)
    QLabel labelPresenceCarte;  /// Affichage carte USB est branchée ou pas
    QLabel labelEtatSysteme;    /// Affiche l'état du système


    QChartView *chartView;
    QHBoxLayout *layout;
    QSplineSeries courbeA;
    QSplineSeries courbeO;
    QChart chart;


};
#endif // EQUILIBREUSE_H
