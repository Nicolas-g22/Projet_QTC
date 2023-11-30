#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <iostream>
#include <string>
class Menu
{

private:
    char nom [255];
    char * options [255];
    int nbOptions;
    int longueurMax;
public:
    Menu(const std::string &_nom);
    ~Menu();
    int Afficher();
    void AttendreAppuiTouche();
};

#endif // MENU_H
