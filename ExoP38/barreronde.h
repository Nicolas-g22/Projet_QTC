#ifndef BARRERONDE_H
#define BARRERONDE_H
#include "barre.h"

//Classe fille BarreRonde
class BarreRonde : public Barre
{
protected:
    //Attributs
    float diametre;


public:
    //Constructeur
    BarreRonde(string ref, float longueur, float densite, string nomAllia, float diametre);

    //Fonctions
    float CalculerSection();
    float CalculerMasse();

};


#endif // BARRERONDE_H
