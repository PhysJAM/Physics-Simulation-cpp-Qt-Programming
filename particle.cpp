/*** Custom particle object inhereting from QGraphicsItem with included rudimentary physics
*created by Julio Morgado
***/

#include "particle.h"

Particle::Particle(qreal X, qreal Y, qreal W, qreal H, QString type)
{
    res = 0.95;
    w = W; h = H;
    a = new PVector(0,0);
    v = new PVector(rand()%5 +2, rand()%5 +2);
    p = new PVector(X,Y);
    pType = type;
}

QRectF Particle::boundingRect() const
{
    return QRectF(p->x(), p->y(), w, h);
}

void Particle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen (QColor(0,0,0));
    QRadialGradient grad(QPointF(p->x() + w/2, p->y() + h/2), 0.6 * w);
    grad.setColorAt(0.0, QColor(255,0,255));
    grad.setColorAt(1.0, QColor(0,0,0));

    painter->setPen(pen);
    painter->setBrush(grad);

    if (pType == "Ball" || pType == nullptr){
        painter->drawEllipse(boundingRect());
    }else if(pType == "Box"){
        painter->drawRect(boundingRect());
    }else {
        qDebug() << "invalid pType";
    }

}

void Particle::advance(int phase)
{
    v->add(a);
    p->add(v);

    QPointF location(mapToScene(p->components()));

    if (location.x() >= scene()->width() - (w)){
         p->setX(scene()->width() - (w));
         v->mult(-res, "x");
     }else if (location.x() <= 0){
         p->setX(0);
         v->mult(-res, "x");
     }

     if (location.y() >= scene()->height() - (h)){
         p->setY(scene()->height() - (h));
         v->mult(-res, "y");
     }else if(location.y() <= 0){
         p->setY(0);
         v->mult(-res, "y");
     }

    update();
}
