#include <QCoreApplication>
#include <iostream>
#include "jeu2048.cpp"
#include "plateau.cpp"
//Coucou monsieur le spectateur :D

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Plateau LePlateau;

    bool quit = false;
    do{

        quit = LePlateau.JouerCoup();

    }while(quit == false);

    return a.exec();
}
