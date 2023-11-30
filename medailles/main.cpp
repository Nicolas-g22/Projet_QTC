#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string nomDuFichier;

    //Création du flux en lecture sur le fichier
    ifstream leFichier("/home/USERS/ELEVES/SNIR2022/nguillier/Projet_QTC/medailles/medailles.txt"); // c_str() transforme string en char*
    if (!leFichier.is_open())
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    else
    {
        string pays;
        int nbOr;
        int nbArgent;
        int nbBronze;

        // A compléter, affichage de la première ligne du tableau
        cout << "+" << setfill('-') << setw(21) << "+" << setfill('-') << setw(9) << "+" << setfill('-') << setw(9) << "+" << setfill('-') << setw(9) << "+" << setfill(' ') << endl;
        do
        {
            //récupération des valeurs
            leFichier >> pays >> nbOr >> nbArgent >> nbBronze ;
            if (leFichier.good())//Si les valeurs ont bien été lues
            {
                // A compléter, affichage de chaque ligne du tableau
                cout << "|" << setw(20) << left << pays << right <<"|"<< setw(8) << nbOr << "|" << setw(8) << nbArgent << "|"<< setw(8) << nbBronze << "|" << endl;

            }
        } while (!leFichier.eof());
        // A compléter, affichage de la dernière ligne du tableau.
        cout << "+" << setfill('-') << setw(21) << "+" << setfill('-') << setw(9) << "+" << setfill('-') << setw(9) << "+" << setfill('-') << setw(9) << "+" << endl;
    }
    return 0;
}
