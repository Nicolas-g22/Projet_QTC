#include "jeu2048.h"

//Coucou monsieur le spectateur :D

Jeu2048::Jeu2048()
{
    for(int i = 0; i<TAILLE; i++){
        for(int x = 0; x<TAILLE; x++){
            grille[i][x] = 0;
        }
    }
    srand(time(nullptr));
    PlacerNouvelleTuile();
}
void Jeu2048::ObtenirGrille(int _grille[][TAILLE]){
    for(int ligne = 0; ligne<TAILLE; ligne++){
        for(int colonne = 0; colonne<TAILLE; colonne++){
            _grille[ligne][colonne] = grille[ligne][colonne];
        }
    }
}


void Jeu2048::PlacerNouvelleTuile(){
    int nTuile = 0;
    int rLigne;
    int rColonne;

    do{
        rLigne = rand() %4;
        rColonne = rand() %4;
        if(grille[rLigne][rColonne] == 0){
            grille[rLigne][rColonne] = (((rand() % 2) +1 ) * 2);
        }
    }while(nTuile != 2);
}

void Jeu2048::Deplacer(const char _direction)
{
    int ligne;
    int colonne;
    for(int indice = 0 ; indice < 4 ; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne+1];
                        grille[ligne][colonne+1] = 0;
                    }
                }
            }
            break;

        case 'D':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne-1];
                        grille[ligne][colonne-1] = 0;
                    }
                }
            }
            break;

        case 'H':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne] = 0;
                    }
                }
            }
            break;

        case 'B':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne] = 0;
                    }
                }
            }
            break;

        }
    }
}

bool Jeu2048::Calculer(char _direction){
    bool resultat;
    int ligne;
    int colonne;
    for(int indice = 0 ; indice < 4 ; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne+1];
                        grille[ligne][colonne+1] = 0;
                    }
                }
            }
            break;

        case 'D':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne-1];
                        grille[ligne][colonne-1] = 0;
                    }
                }
            }
            break;

        case 'H':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne-1][colonne];
                        grille[ligne-1][colonne] = 0;
                    }
                }
            }
            break;

        case 'B':
            for(ligne = 0 ; ligne < 4 ; ligne++)
            {
                for(colonne = 0 ; colonne < 3 ; colonne++)
                {
                    if(grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne] = 0;
                    }
                }
            }
            break;

        }
    }




    return resultat;
}
