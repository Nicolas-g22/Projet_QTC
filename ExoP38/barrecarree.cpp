#include "barrecarree.h"

//Constructeur
BarreCarree::BarreCarree(string ref, float longueur, float densite, string nomAllia, float cote) : Barre(ref, longueur, densite, nomAllia), cote(cote) {}


//Fonctions
float BarreCarree::CalculerSection(){
    return cote * cote;
}
float BarreCarree::CalculerMasse(){
     return longueur * BarreCarree::CalculerSection() * densite;
}
