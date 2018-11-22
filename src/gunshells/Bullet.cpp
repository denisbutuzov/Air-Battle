#include "Bullet.h"

void Bullet::setSpeed()
{
    speed() = 10;
}

void Bullet::setShotSound()
{
    shotSound().setMedia(QUrl("qrc:/sounds/sounds/bullet.wav"));
}

void Bullet::setPixmap()
{
    QGraphicsPixmapItem::setPixmap(QPixmap(":/images/images/bullet.png"));
}

Bullet::Bullet(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    loadSettings();
    shotSound().play();
}
