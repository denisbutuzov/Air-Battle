#include <QMediaPlayer>

#include "Gunshell.h"

Gunshell::Gunshell(QGraphicsScene *scene, qreal x, qreal y)
    : MovableObject(scene)
    , x_(x)
    , y_(y)
{
}

Gunshell::~Gunshell()
{
    delete shotSound_;
}

void Gunshell::init()
{
    MovableObject::init();
    playShotSound();
    setDamage();
}

unsigned int Gunshell::damage() const
{
    return damage_;
}

void Gunshell::move()
{  
    //move gun shell up
    setPos(x(), y() - speed());

    //delete gun shell
    if(y() + pixmap().height() < 0)
    {
        destroy(this);
    }
}

void Gunshell::setDamage(unsigned int damage)
{
    damage_ = damage;
}

void Gunshell::setDamage()
{
    setDamage(1);
}

void Gunshell::setStartObjectPos()
{
    setPos(x_, y_);
}

void Gunshell::setSpeed()
{
    MovableObject::setSpeed(10);
}

void Gunshell::playShotSound()
{
    shotSound_ = new QMediaPlayer();
    shotSound_->setMedia(QUrl(pathToShotSound()));
    shotSound_->play();
}
