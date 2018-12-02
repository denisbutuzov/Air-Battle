#pragma once

#include "GunShell.h"

class Bullet
        : public GunShell
{
public:
    Bullet(QGraphicsItem *parent = nullptr);
private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;
    virtual void setDamage() override final;
    virtual QString pathToSound() override final;
};
