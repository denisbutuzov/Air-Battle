#include "HandWeapon.h"

class HandBazooka
        : public HandWeapon
{
public:
    HandBazooka(QGraphicsScene *scene);

    virtual void shoot(qreal x, qreal y) override final;
};
