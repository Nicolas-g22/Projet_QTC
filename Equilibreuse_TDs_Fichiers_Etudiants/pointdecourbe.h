/**
 * @file pointdecourbe.h
 * @date Création 19 janvier 2018
 * @version 2.0
 * @author Philippe CRUCHET
 * @details Classe PointDeCourbe : Surcharge de QPointF pour la recherche dans une QList
 */

#ifndef POINTDECOURBE_H
#define POINTDECOURBE_H

#include <QPointF>

class PointDeCourbe : public QPointF
{
public:
    PointDeCourbe(qreal x,qreal y);
    PointDeCourbe();
    bool operator < (const QPointF &point);
};

#endif // POINTDECOURBE_H
