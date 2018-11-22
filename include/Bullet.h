#pragma once

#include "GunShell.h"

class Bullet: public GunShell
{
private:
    virtual void setSpeed() override final;
    virtual void setShotSound() override final;
    virtual void setPixmap() override final;
public:
    Bullet(QGraphicsItem *parent = nullptr);
};
