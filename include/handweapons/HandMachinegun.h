#include "IHandWeapon.h"

class HandMachinegun
        : public IHandWeapon
{
public:
    HandMachinegun() = default;
    virtual void shoot(QGraphicsScene *scene, qreal x, qreal y) override final;
};
