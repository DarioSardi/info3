#include "Spaceship.h"
#include "Asteroid.h"
#include <QKeyEvent>
#include <QtDebug>
#include <QPen>
#include <math.h>
#include "Projectile.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>
#include <QShortcut>


Spaceship::Spaceship(MyGame *g){
    game=g;
    setPixmap(QPixmap(":/sprites/falcon.png").scaled(QSize(60,60),Qt::KeepAspectRatio));
    this->setTransformOriginPoint(boundingRect().center());
    this->speed=0;
    QTimer * bulletTimer = new QTimer();
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(move()));
    bulletTimer->start(40);
}




//void Spaceship::keyPressEvent(QKeyEvent *event){
//    if( event->key() == Qt::Key_Left){
//        setRotation(rotation()-15);
//    }
//    else if( event->key() == Qt::Key_Right){
//        setRotation(rotation()+15);
//    }
//    else if( event->key() == Qt::Key_Up){
//            if(speed<=40){
//            speed+=2; }

//        }
//    else if( event->key() == Qt::Key_Space){
//            double angle=-(rotation()+180)*M_PI/180;
//            Projectile *p = new Projectile(this);
//            p->setPos(x()+30+30*sin(angle),y()+30+30*cos(angle));
//            p->setRotation(rotation());
//            scene()->addItem(p);
//    }
//    else{
//        qDebug() << "none";
//    }
//    if(rotation()==360 or rotation()==-360) setRotation(0);

//}




void Spaceship::keyPressEvent(QKeyEvent *ev){
  keysPressed += (Qt::Key)ev->key();
}
void Spaceship::keyReleaseEvent(QKeyEvent *ev){
  keysPressed -= (Qt::Key)ev->key();
}
void Spaceship::move(){
    foreach(Qt::Key k, keysPressed){
      switch(k){
      case Qt::Key_Left:setRotation(rotation()-15);
                        break;
      case Qt::Key_Right:setRotation(rotation()+15);
                        break;
      case Qt::Key_Up: if(speed<=30){speed+=2;};
                        break;
      case Qt::Key_Space:{
                     double angle=-(rotation()+180)*M_PI/180;
                     Projectile *p = new Projectile(this);
                     p->setPos(x()+30+30*sin(angle),y()+30+30*cos(angle));
                     p->setRotation(rotation());
                     scene()->addItem(p);};
                     break;
      default:break;
      }
    }
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

    if(speed>0){
    speed-=0.1;}
}

