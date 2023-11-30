#include "vecteur.h"

Vecteur Vecteur::operator+(const Vecteur &_autre)
{
    return Vecteur(x +_autre.x, y + _autre.y);
}


bool Vecteur::operator==(const Vecteur &_autre)
{
    bool retour = false;
    if(x == _autre.x && y == _autre.y)
        retour = true;
    return retour;
}

int Vecteur::getX() const
{
    return x;
}
void Vecteur::setX(int _newX)
{
    x = _newX;
}

Vecteur::Vecteur(const int _x, const int _y):
    x(_x),
    y(_y)
{
}
