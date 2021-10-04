#ifndef MYGAME_H
#define MYGAME_H
#include <QGraphicsScene>
#include <QList>
class Asteroid;
class MyGame{
public:
    MyGame(QGraphicsScene *s);
    ~MyGame();
    void start();
    void spawnLarge(int x,int y);
    void spawnMedium(int x,int y);
    void spawnSmall(int x,int y);
    void victory();
    QList <Asteroid*> asteroidsList;
private:
    QGraphicsScene* scena;
};
#endif // MYGAME_H
