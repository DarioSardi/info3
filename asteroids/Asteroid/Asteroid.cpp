#include "Asteroid.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <QtDebug>
#include <QRandomGenerator>
#include <QString>

Asteroid::Asteroid(MyGame* g) {
    game =g;
    asteroidTimer = new QTimer();
    connect(asteroidTimer,SIGNAL(timeout()),this,SLOT(move()));
    asteroidTimer->start(20);
    setRotation(QRandomGenerator::global()->bounded(360 * 16));

}

Asteroid::~Asteroid()
{
    delete asteroidTimer;
}

void Asteroid::hit(){
    scene()->removeItem(this);
    asteroidTimer->stop();
    this->kill();
}

void Asteroid::move(){
    double angle=-(rotation()+180)*M_PI/180;
    setPos(x()+speed*sin(angle),y()+speed*cos(angle));
    if(x()>800){
        setX(0);
    }
    else if (x()<-5){
        setX(800);
    }

    if(y()>600){
        setY(0);
    }
    else if(y()<-10){
        setY(600);
    }
//     qDebug() << "asteroid online at" << x() << ", "<< y() ;
}

QString Asteroid::toString(){
    QString s="i'm an asteroid at"+QString::number(this->x())+","+QString::number(this->y());
    return s;
}

Large::Large(MyGame* g):Asteroid(g){
    setPixmap(QPixmap(":/sprites/deathstar.png").scaled(QSize(60,60),Qt::KeepAspectRatio));
}

void Large::kill(){
    game->spawnMedium(x(),y());
    game->spawnMedium(x(),y());
    delete this;
}

Medium::Medium(MyGame* g):Asteroid(g){
    setPixmap(QPixmap(":/sprites/tie.png").scaled(QSize(40,40),Qt::KeepAspectRatio));
    this->speed=5;
}
void Medium::kill(){
    game->spawnSmall(x(),y());
    game->spawnSmall(x(),y());
    delete this;
}

Small::Small(MyGame* g):Asteroid(g){
    setPixmap(QPixmap(":/sprites/tie.png").scaled(QSize(25,25),Qt::KeepAspectRatio));
    this->speed=5;
}
void Small::kill(){
    delete this;
    this->game->victory();
}

QString Small::toString(){
    QString s="i'm a small asteroid at"+QString::number(this->x())+","+QString::number(this->y());
    return s;
}
