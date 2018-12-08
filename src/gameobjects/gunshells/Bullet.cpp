#include "Bullet.h"

Bullet::Bullet(QGraphicsItem *parent)
    : Gunshell(parent)
{
}

Bullet::Bullet(qreal x, qreal y)
    : Gunshell(x, y)
{
}

void Bullet::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/bullet.png"));
}

QString Bullet::pathToSound()
{
    return QString("qrc:/sounds/sounds/bullet.wav");
}



