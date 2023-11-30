/**
 * @file pointdecourbe.cpp
 * @date Création 19 janvier 2018
 * @version 2.0
 * @author Philippe CRUCHET
 * @details Classe PointDeCourbe : Surcharge de QPointF pour la recherche dans une QList
 */

#include "pointdecourbe.h"

/**
 * @brief PointDeCourbe::PointDeCourbe
 * @param x
 * @param y
 * @details Constructeur de la classe avec paramètres
 */
PointDeCourbe::PointDeCourbe(qreal x, qreal y):
    QPointF(x,y)
{

}

/**
 * @brief PointDeCourbe::PointDeCourbe
 * @details Constructeur de la classe sans paramètre
 */
PointDeCourbe::PointDeCourbe():QPointF()
{

}

/**
 * @brief PointDeCourbe::operator <
 * @param point
 * @return booléen VRAI si P1 < P2 sinon FAUX
 * @details surcharge de l'opérateur < pour la recherche dans la QList
 */
bool PointDeCourbe::operator <(const QPointF &point)
{
    return y() < point.y();
}
