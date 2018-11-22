#include "Rocket.h"

void Rocket::setSpeed()
{
    speed() = 7;
}

void Rocket::setShotSound()
{
    shotSound().setMedia(QUrl("qrc:/sounds/sounds/rocket.wav"));
}

void Rocket::setPixmap()
{
    QGraphicsPixmapItem::setPixmap(QPixmap(":/images/images/rocket.png"));
}

Rocket::Rocket(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    loadSettings();
}
