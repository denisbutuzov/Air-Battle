#include <QMediaPlayer>

#include "Gunshell.h"

Gunshell::Gunshell(QGraphicsScene *scene, qreal x, qreal y,
                   MoveStrategy *moveStrategy)
    : MovableObject(scene, moveStrategy)
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

void Gunshell::OnMeetOtherObject(GameObject *otherObject)
{

}

void Gunshell::playShotSound()
{
    shotSound_ = new QMediaPlayer();
    shotSound_->setMedia(QUrl(pathToShotSound()));
    shotSound_->play();
}
