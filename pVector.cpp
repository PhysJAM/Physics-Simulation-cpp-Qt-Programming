/*** Custom vector class inhereting from QVector2D
*created by Julio Morgado
***/

#include "pVector.h"

PVector::PVector(qreal x, qreal y)
{
    setVector(x,y);
}

void PVector::setVector(qreal x, qreal y)
{
    setX(x);
    setY(y);
}

void PVector::add(PVector *vec)
{
    setX(x() + vec->x());
    setY(y() + vec->y());
}

void PVector::sub(PVector *vec)
{
    setX(x() - vec->x());
    setY(y() - vec->y());
}

qreal PVector::mag()
{
    return qSqrt( qPow(x() , 2) + qPow(y() ,2) );
}

void PVector::mult(qreal scalar, QString axis)
{
    if (axis == "x" || axis == "X"){
        setX(x() * scalar);
    }else if (axis == "y" || axis == "Y"){
        setY(y() * scalar);
    }else{
        setX(x() * scalar);
        setY(y() * scalar);
    }


}

QPointF PVector::components()
{
    return QPointF(x(), y());
}
