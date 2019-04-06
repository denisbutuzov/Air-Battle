#pragma once

#include <QtGlobal>
#include <memory>

class QGraphicsScene;
class Gunshell;

class HandWeapon
{
public:
    HandWeapon(const std::shared_ptr<QGraphicsScene> &scene);
    virtual ~HandWeapon() = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y);

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
