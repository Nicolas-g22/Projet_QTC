#include "barreronde.h"

//Constructeur
BarreRonde::BarreRonde(string ref, float longueur, float densite, string nomAllia, float diametre) : Barre(ref, longueur, densite, nomAllia), diametre(diametre){}


//Fonctions
float BarreRonde::CalculerMasse(){
     return longueur * BarreRonde::CalculerSection()* densite;
}

float BarreRonde::CalculerSection(){

    return 3.14*(diametre * diametre)/4;
}
