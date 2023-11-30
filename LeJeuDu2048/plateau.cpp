#include "plateau.h"
#include <cstdlib>

//Coucou monsieur le spectateur :D

using namespace std;
Plateau::Plateau()
{
    nbCoups = 0;
    score = 0;
}
//Coucou monsieur le spectateur :D
void Plateau::Afficher()
{
    int laGrille[TAILLE][TAILLE];
    int val[4];
    system("clear");
    leJeu.ObtenirGrille(laGrille);
    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;
    for(int ligne = 0 ; ligne < 4 ; ligne++)
    {
        for(int i = 0; i<TAILLE; i++){
            val[i] = laGrille[ligne][i];
            if(val[i] == 0){
                val[i] = 0 ;
            }
        }
        cout << "+" << setfill("------+") << setw(6)  <<endl;
        cout << "|" << setfill("") << setw(5) << val[0] << right << "|" << setw(5) << val[1] << right << "|" << setw(5) << val[2] << right << "|" <<  setw(5) << val[3] << right << "|" << endl;
    }
    cout << "+" << setfill("------+") << setw(6)  <<endl;
    cout << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H (^), B (v), G(<-), D(->) : " << endl;

}


bool Plateau::JouerCoup(char in_direction){
    bool retour = false;
    char touche = in_direction;

    touche = toupper(touche);
    if(strchr("BHGD",touche) != nullptr)
    {
        nbCoups++;
        leJeu.Deplacer(touche);
        leJeu.PlacerNouvelleTuile();
        Afficher();
    }
    if(touche == 'F')
        retour = true;

    return retour;
}
