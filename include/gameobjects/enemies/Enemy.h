#pragma once

#include "GunShell.h"

#include "SpawnObject.h"

class Enemy
        : public SpawnObject
{
public:
    Enemy(QGraphicsItem *parent = nullptr);
public slots:
    virtual void move() override final;
private:
    void collision(GunShell *gunshell);
    virtual void setObjectImage() override;
    virtual void setHitpoint();
private:
    int hitpoint_;
};
