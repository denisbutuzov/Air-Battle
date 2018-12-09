#pragma once

#include <QGraphicsScene>

class IHandWeapon
{
public:
    virtual ~IHandWeapon() = default;
    virtual void shoot(QGraphicsScene *scene, qreal x, qreal y) = 0;
};
