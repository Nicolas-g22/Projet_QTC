#ifndef VECTEUR_H
#define VECTEUR_H
class Vecteur
{
public:
    Vecteur(const int _x=0,const int _y=0);
    int getX() const;
    void setX(int _newX);
    int getY() const;
    void setY(int _newY);
    Vecteur operator+ (const Vecteur &_autre);
    bool operator==(const Vecteur &_autre);
    void Afficher();
private:
    int x;
    int y;
};
#endif // VECTEUR_H
