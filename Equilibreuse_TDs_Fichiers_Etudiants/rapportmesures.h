#ifndef RAPPORTMESURES_H
#define RAPPORTMESURES_H

#include <QFont>
#include <QPdfWriter>
#include <QPainter>
#include <QChartView>
#include "experience.h"
class RapportMesures : public QPdfWriter
{
public:
    RapportMesures(Experience &_experience, QChartView &_graphique, const QString &_nomDuFichier);
    ~RapportMesures();
    void ConstruireRapport();
private:
    int largeurPdf;
    int hauteurPdf;
    int margeGauche;
    int margeHaut;
    int largeurUtile;
    int padding;
    QFont fontTitre;
    QFont fontTexte;
    QPainter painter;
    QChartView &graphique;
    Experience &experience;

    void FabriquerEnTete();
    void FabriquerResultats(int position);
    void FabriquerGraphique(int position);
    void FabriquerCommentaire(int position);
};

#endif // RAPPORTMESURES_H
