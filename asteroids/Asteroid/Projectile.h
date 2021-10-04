#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsRectItem>
#include <QObject>
#include <Spaceship.h>
class Projectile: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT //macro needed for sign-slots
public:
    Projectile(Spaceship *s);
    int speed =40;
    ~Projectile();
public slots:
    void move();
private:
    QTimer *bulletTimer;
    void check();
    Spaceship *mother;
};


#endif // PROJECTILE_H
