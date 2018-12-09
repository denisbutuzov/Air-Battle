#include "IHandWeapon.h"

class HandBazooka
        : public IHandWeapon
{
public:
    HandBazooka() = default;
    virtual void shoot(QGraphicsScene *scene, qreal x, qreal y) override final;
};
