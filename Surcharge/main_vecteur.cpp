#include <iostream>
#include "vecteur.h"
using namespace std;
int main()
{
    Vecteur va(4,4);
    Vecteur vb(4,1);
    if(va == vb)
        cout << "les vecteurs sont identiques" << endl;
    else
        cout << "va est différent de vb" << endl;
    return 0;
}
