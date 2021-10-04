#include "Projectile.h"
#include "Asteroid.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>

Projectile::Projectile(Spaceship *s)
{
    mother = s;
    setPixmap(QPixmap(":/sprites/laser.png").scaled(QSize(10,25),Qt::KeepAspectRatio));
    bulletTimer = new QTimer();
    connect(bulletTimer,SIGNAL(timeout()),this,SLOT(move()));
    bulletTimer->start(50);
}

Projectile::~Projectile()
{
    delete bulletTimer;
}
void Projectile::check(){
    for(Asteroid *ast: mother->game->asteroidsList){
        bool xCollision= (x()>ast->x()-30) && (x()<ast->x()+30);
        bool yCollision= (y()>ast->y()-30) && (y()<ast->y()+30);
        if(xCollision && yCollision){
            qDebug() << "HIT! remaining:" << mother->game->asteroidsList.length();
            ast->hit();
            mother->game->asteroidsList.removeAll(ast);
//            qDebug() << "removed! remaining:" << mother->game->asteroidsList.length();
            if(this->mother->game->asteroidsList.length()==0){
                mother->game->victory();
            }
            delete this;
            break;
        }
    }
}


void Projectile::move()
{
    double angle=-(rotation()+180)*M_PI/180;
    setPos(x()+speed*sin(angle),y()+speed*cos(angle));
    if(y()<-20 or y()>600){
        scene()->removeItem(this);
        delete this;
    }
    else{
    check();
    }


}

