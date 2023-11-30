#ifndef BARRE_H
#define BARRE_H
#include <iostream>

//Flemme de mettre des p**ain de std::
using namespace std;


// Initialisation de la classe mère Barre
class Barre
{
protected: // Protected pour laisser l'acces au attributs de la classe mère
    //Attributs
    string ref;
    float longueur;
    float densite;
    string nomAllia;


public:
    //Constructeur
    Barre(string ref, float longueur, float densite, string nomAllia);

    //Fonctions
    void AfficherCaracteristique();

};
#endif // BARRE_H
