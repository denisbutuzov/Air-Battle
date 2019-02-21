#pragma once

#include "Gunshell.h"

class Bullet
        : public Gunshell
{
public:
    Bullet(QGraphicsScene *scene, qreal x, qreal y, MoveStrategy *moveStrategy = new MoveByLine(MoveStrategy::DIRECTION::UP));
    virtual ~Bullet() override = default;

private:
    virtual void setObjectImage() override final;
    virtual QString pathToShotSound() const override final;
};
