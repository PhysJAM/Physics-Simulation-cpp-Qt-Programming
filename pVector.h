#ifndef PVECTOR_H
#define PVECTOR_H

#include <QVector2D>
#include <QtMath>

class PVector: public QVector2D {
public:

    PVector(qreal x=0, qreal y=0);
    void setVector(qreal x, qreal y);
    void add(PVector *vec);
    void sub(PVector *vec);
    qreal mag();
    void mult(qreal scalar, QString axis = nullptr);
    QPointF components();

};

#endif // PVECTOR_H
