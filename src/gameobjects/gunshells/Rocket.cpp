#include "Rocket.h"

Rocket::Rocket(QGraphicsScene *scene, qreal x, qreal y,
               MoveStrategy *moveStrategy)
    : Gunshell(scene, x, y, moveStrategy)
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

QString Rocket::pathToShotSound() const
{
    return QString("qrc:/sounds/sounds/rocket.wav");
}
