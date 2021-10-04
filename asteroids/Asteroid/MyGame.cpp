#include <MyGame.h>
#include <Asteroid.h>
#include <Spaceship.h>
#include <QRandomGenerator>
#include <Qlabel.h>

MyGame::MyGame(QGraphicsScene *s)
{
    scena = s;
}

void MyGame::start()
{
    Spaceship * spaceship = new Spaceship(this);
    spaceship->setPos(400,300);
    spaceship->setFlag(QGraphicsItem::ItemIsFocusable);
    spaceship->setFocus();
    scena->addItem(spaceship);
    asteroidsList = QList<Asteroid *>();
    for (int x=0;x<5 ;x++ ) {
        int x1=QRandomGenerator::global()->bounded(0,800);
        int y1=QRandomGenerator::global()->bounded(0,600);
        spawnLarge(x1,y1);
        }
    qDebug() << "init:" << this->asteroidsList.length();

}

void MyGame::victory(){
    if(this->asteroidsList.empty()){
        qDebug() << "YOU WIN!";
        QLabel *label = new QLabel();
        label->setText("YOU\ WIN!");
        label->resize(800,600);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setStyleSheet("QLabel { background-color : transparent; color : white;font-size:75px; }");
        this->scena->addWidget(label);


    }
}



void MyGame::spawnLarge(int x,int y)
{
    Asteroid *a= new Large(this);
    this->asteroidsList.append(a);
    scena->addItem(a);
    a->setX(x);
    a->setY(y);
}

void MyGame::spawnMedium(int x,int y)
{
    Asteroid *a= new Medium(this);
    this->asteroidsList.append(a);
    scena->addItem(a);
    a->setX(x);
    a->setY(y);
}

void MyGame::spawnSmall(int x,int y)
{
    Asteroid *a= new Small(this);
    this->asteroidsList.append(a);
    scena->addItem(a);
    a->setX(x);
    a->setY(y);
}
