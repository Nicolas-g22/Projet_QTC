#include <iostream>
#include "IPv4.h"
using namespace std;
void AfficherTableau(const unsigned char *tab);
int main()
{
    unsigned char adresse[4]= {192,168,1,1};
    unsigned char reseau[4];
    IPv4 * uneAdresse = new IPv4(adresse, 24); // instanciation de la classe IPv4
    IPv4 adresseCopie = *uneAdresse; // l'instance est recopiée dans une autre
    cout << "Adresse réseau avant : ";
    adresseCopie.ObtenirAdresseReseau(reseau);
    AfficherTableau(reseau);
    delete uneAdresse; // destruction de la première instance
    cout << "Adresse réseau après destruction : ";
    adresseCopie.ObtenirAdresseReseau(reseau);
    AfficherTableau(reseau);
    return 0;
}
