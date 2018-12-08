#include "Gunshell.h"

Gunshell::Gunshell(QGraphicsItem *parent)
    : MovableObject(parent)
{
}

Gunshell::Gunshell(qreal x, qreal y)
    : startX_(x)
    , startY_(y)
{
}

Gunshell::~Gunshell()
{
    delete shotSound_;
}

void Gunshell::init(QGraphicsScene *scene)
{
    MovableObject::init(scene);
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
    setPos(startX_, startY_);
}

void Gunshell::setSpeed()
{
    MovableObject::setSpeed(10);
}

void Gunshell::playShotSound()
{
    shotSound_ = new QMediaPlayer();
    shotSound_->setMedia(QUrl(pathToSound()));
    shotSound_->play();
}
