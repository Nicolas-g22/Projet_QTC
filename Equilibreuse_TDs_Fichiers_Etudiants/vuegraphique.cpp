/**
 * @file vuegraphique.cpp
 * @date Création 19 janvier 2018
 * @version 2.0
 * @author Philippe CRUCHET
 * @details Classe VueGraphique : Affiche les courbes
 */

#include "vuegraphique.h"
#include "constante.h"

/**
 * @brief VueGraphique::VueGraphique
 * @param _ptrExperience pointeur sur l'expérience.
 * @param parent
 * @details Constructeur de la classe, initialise les attriuts
 *          par défaut la courbe est en Newton et en degré
 */
VueGraphique::VueGraphique(Experience *_experience, QChart *parent) :
    QChart(parent),
    courbeA(nullptr),
    courbeO(nullptr),
    experience(_experience),
    newton(true),
    degre(true)
{

}

/**
 * @brief VueGraphique::~VueGraphique
 * @details Destructeur de la classe
 */
VueGraphique::~VueGraphique()
{
    if(courbeA  != nullptr)
        delete courbeA;
    if(courbeO != nullptr)
        delete courbeO;
}

/**
 * @brief VueGraphique::DessinerCourbes
 * @return Pointeur sur QChart
 * @details Réalise le tracé des deux courbes, des axes et des légendes
 */
QChart *VueGraphique::DessinerCourbes()
{
    pointsDeA = experience->ObtenirCourbeA();
    pointsDeO = experience->ObtenirCourbeO();

    experience->ObtenirTypeAffichage(newton,degre);
    if(!pointsDeA->isEmpty() && !pointsDeO->isEmpty())
    {
        QString titre = "Efforts sur les paliers de roulement en fonction de la position angulaire  ";
        setTitle(titre);

        if(courbeA  != nullptr)
            delete courbeA;
        if(courbeO != nullptr)
            delete courbeO;

        courbeA = new QSplineSeries(this);
        courbeO = new QSplineSeries(this);

        courbeA->append(*pointsDeA);
        courbeO->append(*pointsDeO);

        addSeries(courbeA);
        addSeries(courbeO);
        createDefaultAxes();

        courbeA->setName("Palier A");
        QPen penA = courbeA->pen();
        penA.setColor(COULEUR_PALIER_A);
        courbeA->setPen(penA);

        courbeO->setName("Palier O");

        QPen penO = courbeO->pen();
        penO.setColor(COULEUR_PALIER_O);
        courbeO->setPen(penO);

        QValueAxis *axeX = (QValueAxis *)axisX();
        axeX->applyNiceNumbers();
        axeX->setTickCount(5);
        axeX->setMinorTickCount(2);
        axeX->setLabelFormat("%d");
        if(!degre)
        {
            axeX->setMax(360);
            axeX->setTitleText("Position en degré");
        }
        else
        {
            axeX->setMax(2000);
            axeX->setTitleText("Points du codeur");
        }

        QValueAxis *axeY = (QValueAxis *)axisY();
        axeY->setTickCount(9);
        axeY->applyNiceNumbers();
        axeY->setMinorTickCount(10);
        if(newton)
            axeY->setTitleText("Force en Newton");
        else
            axeY->setTitleText("Tension en Volts");
    }

    return this;
}

