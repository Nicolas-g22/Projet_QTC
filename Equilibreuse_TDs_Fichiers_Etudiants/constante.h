#ifndef CONSTANTE_H
#define CONSTANTE_H

//  Définition pour les courbes
#define NB_PALIER 2
#define COULEUR_PALIER_A Qt::blue
#define COULEUR_PALIER_O Qt::red
#define PALIER_A 0
#define PALIER_O 1

// Définition de l'aspect matériel
#define NOM_CARTE "Equilibreuse"
#define BROCHE_CAPOT "/port0/line3"
#define INDEX_CODEUR "/PFI2"
#define COMPTEUR_VITESSE "/ctr0"
#define BROCHE_MOTEUR "/ao0"
#define NB_POINTS_CODEUR 1000
#define LIMITE_VITESSE_BASSE 70
#define LIMITE_VITESSE_HAUTE 90
#define VITESSE_MOTEUR_MAXI  2000 // 4 volts pour 2000 tr/mn
#define BROCHE_JAUGE_A "/ai13"
#define BROCHE_JAUGE_O "/ai6"
#define HORLOGE_EXTERNE_CODEUR_VOIE_A "/PFI0"

// Définition des Temps pour les timer
#define TEMPO_CAPOT 200
#define TEMPO_PRISE_ORIGINE 200
#define TEMPO_VITESSE 500
#define TEMPO_ACQUISITION 500

// Définition pour les mesures
#define NB_ACQUISITIONS_PAR_PERIODE 1000
#define NB_ECHANTILLONS_PAR_CANAL 2000

#endif // CONSTANTE_H
