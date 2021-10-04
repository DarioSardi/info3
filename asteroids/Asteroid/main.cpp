#include "mainwindow.h"
#include <Spaceship.h>
#include <Asteroid.h>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QBrush>
#include <QPoint>
#include <MyGame.h>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //scene (just info)
    QGraphicsScene *scene= new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QBrush brush(QColor::fromRgb(58, 64, 85));
    scene->setBackgroundBrush(brush);
    MyGame *g=new MyGame(scene);
    g->start();
    QGraphicsView * view=new QGraphicsView(scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();
    return a.exec();
}
