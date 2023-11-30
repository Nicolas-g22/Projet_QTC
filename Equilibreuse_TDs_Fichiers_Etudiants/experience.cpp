#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QDataStream>
#include <QPointF>


#include "experience.h"

Experience::Experience(QObject *parent) : QObject(parent)
  , vitesseMaxi(0)
  , configExperience(false)
  , nbEchantillons(0)
  , origine(0)
  , vitesse(0)
  , mesuresBrutes(nullptr)

{
    LireFichierIni();
}

void Experience::LireFichierIni()
{
    QString nomFichierIni = "equilibreuse.ini";
    QFileInfo fichierIni(nomFichierIni);
    if (fichierIni.exists() && fichierIni.isFile())
    {
        QSettings param(nomFichierIni,QSettings::IniFormat);
        paliers[PALIER_A].jauge.modele = param.value("JaugeA/modele").toString();
        paliers[PALIER_A].jauge.numeroDeSerie = param.value("JaugeA/serie").toString();
        paliers[PALIER_A].jauge.date = param.value("JaugeA/date").toString();
        paliers[PALIER_A].jauge.capacite = param.value("JaugeA/capacite").toDouble();
        paliers[PALIER_A].jauge.sensibilite = param.value("JaugeA/sensibilite").toDouble();

        paliers[PALIER_O].jauge.modele = param.value("JaugeO/modele").toString();
        paliers[PALIER_O].jauge.numeroDeSerie = param.value("JaugeO/serie").toString();
        paliers[PALIER_O].jauge.date = param.value("JaugeO/date").toString();
        paliers[PALIER_O].jauge.capacite = param.value("JaugeO/capacite").toDouble();
        paliers[PALIER_O].jauge.sensibilite = param.value("JaugeO/sensibilite").toDouble();
    }
    else
    {
        paliers[PALIER_A].jauge.modele = "MB-25";
        paliers[PALIER_A].jauge.numeroDeSerie = "C30629";
        paliers[PALIER_A].jauge.date = "09-22-1998";
        paliers[PALIER_A].jauge.capacite = 25;
        paliers[PALIER_A].jauge.sensibilite = 3.348;

        paliers[PALIER_O].jauge.modele = "MB-25";
        paliers[PALIER_O].jauge.numeroDeSerie = "C30637";
        paliers[PALIER_O].jauge.date = "10-05-1998";
        paliers[PALIER_O].jauge.capacite = 25;
        paliers[PALIER_O].jauge.sensibilite = 3.328;

        EnregistreFichierIni(paliers);
    }
}

void Experience::EnregistreFichierIni(const typePalier _paliers[])
{
    QString nomFichierIni = "equilibreuse.ini";
    QFileInfo fichierIni(nomFichierIni);
    QSettings param(nomFichierIni,QSettings::IniFormat);
    param.beginGroup("JaugeA");
    param.setValue("modele",_paliers[PALIER_A].jauge.modele);
    param.setValue("serie",_paliers[PALIER_A].jauge.numeroDeSerie);
    param.setValue("date",_paliers[PALIER_A].jauge.date);
    param.setValue("capacite",_paliers[PALIER_A].jauge.capacite);
    param.setValue("sensibilite",_paliers[PALIER_A].jauge.sensibilite);
    param.endGroup();

    param.beginGroup("JaugeO");
    param.setValue("modele",paliers[PALIER_O].jauge.modele);
    param.setValue("serie",paliers[PALIER_O].jauge.numeroDeSerie);
    param.setValue("date",paliers[PALIER_O].jauge.date);
    param.setValue("capacite",paliers[PALIER_O].jauge.capacite);
    param.setValue("sensibilite",paliers[PALIER_O].jauge.sensibilite);
    param.endGroup();
}

typePalier *Experience::ObtenirCarateristiquesPaliers()
{
    return paliers;
}

void Experience::LireMesuresBrutes(QString &_nomFichier)
{
    QFile fichierBrute(_nomFichier);
    if (!fichierBrute.open(QIODevice::ReadOnly))
        qDebug() << "Le Fichier " << _nomFichier << " ne peut pas s'ouvrir";

    else
    {
        QDataStream flux(&fichierBrute);
        flux >> nbEchantillons;
        flux >> vitesse;
        flux >> origine ;

        if (mesuresBrutes != nullptr)
        {
            delete[] mesuresBrutes;
            mesuresBrutes = nullptr;
        }

        if(mesuresBrutes == nullptr)
            mesuresBrutes = new double[nbEchantillons];

        for(quint32 i = 0 ; i < nbEchantillons ; i++)
            flux >> mesuresBrutes[i] ;

        fichierBrute.close();
    }
}

void Experience::InitiliserCourbes()
{
    int indiceFin = nbEchantillons / 2 ;
    int indiceA = 0;
    int indiceO = nbEchantillons /2 ;

    courbeA.clear();
    courbeO.clear();
    PointDeCourbe unPoint;
    for(int i = 0 ; i < indiceFin ; i++)
    {
        unPoint.setX(i);
        unPoint.setY(mesuresBrutes[indiceA++]);
        courbeA.append(unPoint);
        unPoint.setY(mesuresBrutes[indiceO++]);
        courbeO.append(unPoint);
    }
}

QList<QPointF> *Experience::ObtenirCourbeA()
{
    return (QList<QPointF>*) &courbeA;
}

QList<QPointF> *Experience::ObtenirCourbeO()
{
    return (QList<QPointF>*) &courbeO;
}

void Experience::ObtenirTypeAffichage(bool &_newton, bool &_pointCodeur)
{
    _newton = false;
    _pointCodeur = true;
}

/**
 * @brief Experience::RechercherEffortMax
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return Le point possedant la valeur de l'effort le plus grand
 * @details Recherche le point dont l'amplitude est la plus grande sur l'une des 2 courbes.
 */
QPointF Experience::RechercherEffortMax(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;

    QList<PointDeCourbe>::iterator max = std::max_element(laCourbe->begin(), laCourbe->end());
    return *max;
}

/**
 * @brief Experience::RechercherEffortAzero
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort pour à l'origine de la courbe
 */
double Experience::RechercherEffortAzero(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;
    return laCourbe->at(0).y();
}

/**
 * @brief Experience::RechercherEffortAquatreVingtDix
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort à 90°
 */
double Experience::RechercherEffortAquatreVingtDix(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;
    return laCourbe->at(250).y();   // 90° * 1000 ptsCodeur / 360°
}

/**
 * @brief Experience::ObtenirVitesse
 * @return La vitesse de l'expérience courante
 */
qint16 Experience::ObtenirVitesse()
{
    return vitesse;
}

const QString &Experience::getNom() const
{
    return nom;
}

const QString &Experience::getPrenom() const
{
    return prenom;
}

const QString &Experience::getClasse() const
{
    return classe;
}

QString Experience::ObtenirEtablissement() const
{
    return etablissement;
}

void Experience::ModifierEtablissement(const QString &value)
{
    etablissement = value;
}

QString Experience::ObtenirNom() const
{
    return nomEtudiant;
}

void Experience::ModifierNom(const QString &value)
{
    nomEtudiant = value;
}

QString Experience::ObtenirPrenom() const
{
    return prenomEtudiant;
}

void Experience::ModifierPrenom(const QString &value)
{
    prenomEtudiant = value;
}

QString Experience::ObtenirClasse() const
{
    return classe;
}

void Experience::ModifierClasse(const QString &value)
{
    classe = value;
}

QString Experience::ObtenirCommentaire() const
{
    return commentaire;
}

void Experience::ModifierCommentaire(const QString &value)
{
    commentaire = value;
}

QString Experience::ObtenirDate() const
{
    return date.toString("dddd d MMMM yyyy");
}

void Experience::ModifierDate(const QDate &value)
{
    date = value;
}
void Experience::ValiderConfig(bool _etat)
{
    configExperience = _etat;
}
