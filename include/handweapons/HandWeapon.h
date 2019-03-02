#pragma once

#include <QtGlobal>
#include <memory>

class QGraphicsScene;

class HandWeapon
{
public:
    HandWeapon(const std::shared_ptr<QGraphicsScene> &scene);
    virtual ~HandWeapon() = default;
    virtual void shoot(qreal x, qreal y);

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
