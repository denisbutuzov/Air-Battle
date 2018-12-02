#include "Bullet.h"

Bullet::Bullet(QGraphicsItem *parent)
    : GunShell(parent)
{

}

void Bullet::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/bullet.png"));
}

void Bullet::setStartObjectPos()
{

}

void Bullet::setDamage()
{
    damage() = 1;
}

QString Bullet::pathToSound()
{
    return QString("qrc:/sounds/sounds/bullet.wav");
}



