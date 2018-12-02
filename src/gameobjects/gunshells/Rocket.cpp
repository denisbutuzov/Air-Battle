#include "Rocket.h"

Rocket::Rocket(QGraphicsItem *parent)
    : GunShell(parent)
{

}

void Rocket::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/rocket.png"));
}

void Rocket::setStartObjectPos()
{

}

void Rocket::setDamage()
{
    damage() = 2;
}

QString Rocket::pathToSound()
{
    return QString("qrc:/sounds/sounds/rocket.wav");
}
