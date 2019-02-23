#pragma once

#include <QtGlobal>

class QGraphicsScene;

class HandWeapon
{
public:
    virtual ~HandWeapon() = default;
    virtual void shoot(qreal x, qreal y) = 0;

protected:
    HandWeapon(QGraphicsScene *scene);

    QGraphicsScene *scene() const;

private:
    QGraphicsScene *scene_;
};
