/*** Physics Simulation using the Qt Framework
*created by Julio Morgado
***/

#include "engine.h"
#include "ui_engine.h"

engine::engine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::engine)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    QRect bg(0,0,798, 598);
    scene->setSceneRect(bg);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    spawn(5);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene ,SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this ,SLOT(refreshBg()));
    timer->start(17);

}

engine::~engine()
{
    delete ui;
}

void engine::spawn(int num)
{
    for(int i = 0; i < num; i++){
        qreal d=40;
        qreal x = (rand()%798) + 25 - d;
        qreal y = (rand()%598) + 15 - d;
        Particle * obj = new Particle(x,y,d,d);
        particles << obj;
        scene->addItem(particles.last());
    }
}

void engine::refreshBg()
{
    scene->setBackgroundBrush(QBrush(QColor(100,100,100)));
}

