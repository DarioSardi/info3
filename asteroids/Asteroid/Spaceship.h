#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <Asteroid.h>

class Spaceship: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QTransform trans;
    int speed;
    QSet<Qt::Key> keysPressed;


public:
    void keyPressEvent(QKeyEvent * event);
    Spaceship(MyGame *g);
    MyGame *game;
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void move();
};



#endif // SPACESHIP_H
