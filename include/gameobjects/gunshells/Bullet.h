#pragma once

#include "Gunshell.h"

class Bullet
        : public Gunshell
{
public:
    Bullet(QGraphicsScene *scene, qreal x, qreal y);
    virtual ~Bullet() override = default;

private:
    virtual void setObjectImage() override final;
    virtual QString pathToShotSound() const override final;
};
