#include "barrerectangle.h"

//Constructeur
BarreRectangle::BarreRectangle(string ref, float longueur, float densite, string nomAllia, float largeurR, float longueurR) : Barre(ref, longueur, densite, nomAllia), largeurR(largeurR),longueurR(longueurR){}


//Fonctions
float BarreRectangle::CalculerSection(){
    return largeurR * longueurR;
}
float BarreRectangle::CalculerMasse(){
     return longueur * BarreRectangle::CalculerSection()* densite;
}
