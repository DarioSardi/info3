#ifndef ASTEROID_H
#define ASTEROID_H
#include <MyGame.h>
#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
class Asteroid: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Asteroid(MyGame *g);
    virtual ~Asteroid();
    virtual void kill()=0;
    void hit();
    QString toString();
public slots:
    void move();
protected:
    MyGame *game;
    int speed =10;
    QTimer *asteroidTimer;
};

class Large : public Asteroid{
public:
    Large(MyGame* g);
    void kill();
};


class Medium: public Asteroid{
public:
    Medium(MyGame* g);
    void kill();
};

class Small: public Asteroid{
public:
    Small(MyGame* g);
    void kill();
    QString toString();
};



#endif // ASTEROID_H
