#include "menu.h"

using namespace std;

Menu::Menu(const string &_nom):nom(_nom), longueurMax(0)
{
    // ouvrir le fichier
    ifstream fichier("menu.txt");
    // Si il y a une erreur
    if (!fichier.is_open()){
        // alors Afficher un message indiquant une erreur de lecture
        cerr << "Erreur à l'ouverture du fichier" << endl;
        // et mettre nbOptions à 0
        nbOptions = 0;
    }
    // Sinon calculer nbOptions, le nombre d’options dans le fichier
    else{
        // allouer dynamiquement le tableau options en fonction de nbOptions

        // Pour chaque option dans le fichier

            // Lire l’option et l’affecter dans le tableau options

            // Si la taille de l’option est plus grande que longueurMax

                // alors longueurMax reçoit la taille de l’option

            // FinSi

        // FinPour

    // FinSi
    }

}
