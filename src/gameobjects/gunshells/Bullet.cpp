#include "Bullet.h"

Bullet::Bullet(QGraphicsScene *scene, qreal x, qreal y)
    : Gunshell(scene, x, y)
{
}

void Bullet::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/bullet.png"));
}

QString Bullet::pathToShotSound() const
{
    return QString("qrc:/sounds/sounds/bullet.wav");
}
