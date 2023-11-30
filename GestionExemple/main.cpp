#include "tableau.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    try
    {
        Tableau leTableau(10);
        leTableau.Affecter(5,8);
        leTableau.Affecter(-5,15);
        cout << leTableau[-5] << endl;
        Tableau autre(-12);
    }
    catch(ErreurCreation const &exp)
    {
        cout << "Erreur " << exp.ObtenirCodeErreur() << endl;
        cout << exp.ObtenirDescription() << endl;
        exit (EXIT_FAILURE);
    }
    catch (ErreurIndice const &exp)
    {
        cout << "Erreur " << exp.ObtenirCodeErreur() << endl;
        cout << exp.ObtenirDescription() << endl;
        exit (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}
