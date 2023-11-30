#ifndef CARTON_H
#define CARTON_H
#include "contenant.h"
class Carton : public Contenant
{
public:
    Carton(const int _largeur, const int _hauteur,
           const int _profondeur, const float _poidsMaxi);
    float ObtenirPoidsMaxi();
private:
    float poidsMaxi;
};
#endif // CARTON_H
