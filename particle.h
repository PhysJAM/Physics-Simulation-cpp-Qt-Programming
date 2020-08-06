#ifndef PARTICLE_H
#define PARTICLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include "pVector.h"
#include <QDebug>

class Particle: public QGraphicsItem{
public:
    Particle(qreal X, qreal Y, qreal W, qreal H, QString type = nullptr);

    QRectF boundingRect() const override;
    PVector *p, *v, *a;
    qreal w, h, m, res;
    QString pType;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
    void advance(int phase) override;
};


#endif // PARTICLE_H
