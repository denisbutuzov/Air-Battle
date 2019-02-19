#pragma once

#include "Gunshell.h"

class Rocket
        : public Gunshell
{
public:
    Rocket(QGraphicsScene *scene, qreal x, qreal y, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::UP));
    virtual ~Rocket() override = default;

private:
    virtual void setObjectImage() override final;
    virtual void setDamage() override final;
    virtual QString pathToShotSound() const override final;
};
