#include "barre.h"

//Constructeur
Barre::Barre(string ref, float longueur, float densite, string nomAllia) : ref(ref), longueur(longueur), densite(densite), nomAllia(nomAllia) {}

//Fonctions
void Barre::AfficherCaracteristique(){
    cout << "ref =" << ref << "longueur =" << longueur << "densite =" << densite << "nomAllia = " <<nomAllia << endl;
}
