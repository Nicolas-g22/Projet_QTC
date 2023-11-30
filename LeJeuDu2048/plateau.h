#ifndef PLATEAU_H
#define PLATEAU_H
#include "jeu2048.h"

//Coucou monsieur le spectateur :D

class Plateau : public Jeu2048
{
private:
    int nbCoups;
    int score;
    Jeu2048 leJeu;
public:
    Plateau();
    void Afficher();
    bool JouerCoup(char in_direction);
};

#endif // PLATEAU_H
