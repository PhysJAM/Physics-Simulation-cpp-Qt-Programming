#ifndef ENGINE_H
#define ENGINE_H

#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include "particle.h"
#include <QList>


QT_BEGIN_NAMESPACE
namespace Ui { class engine; }
QT_END_NAMESPACE

class engine : public QDialog
{
    Q_OBJECT

public:
    engine(QWidget *parent = nullptr);
    ~engine();
private:
    Ui::engine * ui;
    QGraphicsScene *scene;
    QTimer * timer;
    QList <Particle*> particles;
protected:
    void spawn(int num);
protected slots:
    void refreshBg();

};
#endif // ENGINE_H
