#ifndef BARRECARREE_H
#define BARRECARREE_H
#include "barre.h"

//Classe fille BarreCarree
class BarreCarree : public Barre
{
protected:
    //Attributs
    float cote;

public:
    //Constructeur
    BarreCarree(string ref, float longueur, float densite, string nomAllia, float cote);

    //Fonctions
    float CalculerSection();
    float CalculerMasse();

};
#endif // BARRECARREE_H
