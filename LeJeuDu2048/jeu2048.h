#ifndef JEU2048_H
#define JEU2048_H
#define TAILLE 4
#include <string.h>
#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
//Coucou monsieur le spectateur :D


class Jeu2048
{
private:
    int grille[TAILLE][TAILLE];

public:
    Jeu2048();
    void PlacerNouvelleTuile();
    bool Calculer(char in_direction);
    void Deplacer(char in_direction);
    int CalculerScore();
    void ObtenirGrille(int ou_grille[][4]);
    //ETATS_DU_JEU RechercherFinDePartie();

protected:
    //char* ETATS_DU_JEU = {"EN_COURS", "PERDU", "GAGNE"};
};

#endif // JEU2048_H
