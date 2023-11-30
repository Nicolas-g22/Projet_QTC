#ifndef TABLEAU_H
#define TABLEAU_H
#include <string>

using namespace std;
class Tableau
{
private:
    int *ptr;
    int taille;
public:
    Tableau(int _taille);
    ~Tableau();
    void Affecter(int _indice, int _valeur);
    int &operator[](int _indice);
};
class ErreurCreation
{
private:
    int codeErreur;
    string message;
public:
    ErreurCreation(int _codeErreur,
                   string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};

class ErreurIndice
{
private:
    int codeErreur;
    string message;
public:
    ErreurIndice(int _codeErreur,
                 string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;
};

enum erreurs
{
    CREATION,
    INDICE
};

#endif // TABLEAU_H


