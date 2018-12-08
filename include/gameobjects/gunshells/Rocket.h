#pragma once

#include "Gunshell.h"

class Rocket
        : public Gunshell
{
public:
    Rocket(QGraphicsItem *parent = nullptr);
    Rocket(qreal x, qreal y);
private:
    virtual void setObjectImage() override final;
    virtual void setDamage() override final;
    virtual QString pathToSound() override final;
};
