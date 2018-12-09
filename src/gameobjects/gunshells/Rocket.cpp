#include "Rocket.h"

Rocket::Rocket(QGraphicsItem *parent)
    : Gunshell(parent)
{
}

Rocket::Rocket(qreal x, qreal y)
    : Gunshell(x, y)
{
}

void Rocket::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/rocket.png"));
}

void Rocket::setDamage()
{
    Gunshell::setDamage(2);
}

QString Rocket::pathToSound()
{
    return QString("qrc:/sounds/sounds/rocket.wav");
}
