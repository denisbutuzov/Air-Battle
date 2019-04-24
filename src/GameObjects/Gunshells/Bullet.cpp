#include "Bullet.h"

Bullet::Bullet(QGraphicsScene *scene, qreal x, qreal y,
               MoveStrategy *moveStrategy)
    : Gunshell(scene, x, y, moveStrategy)
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
