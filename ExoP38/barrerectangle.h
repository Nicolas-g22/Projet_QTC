#ifndef BARRERECTANGLE_H
#define BARRERECTANGLE_H
#include "barre.h"

//Classe fille BarreRectangle
class BarreRectangle : public Barre
{
protected:
    //Attributs
    float largeurR;
    float longueurR;

public:
    //Constructeur
    BarreRectangle(string ref, float longueur, float densite, string nomAllia, float largeurR, float longueurR);

    //Fonctions
    float CalculerSection();
    float CalculerMasse();
};
#endif // BARRERECTANGLE_H
