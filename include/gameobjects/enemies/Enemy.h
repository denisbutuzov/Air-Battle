#pragma once

#include "Gunshell.h"
#include "SpawnObject.h"

class Enemy
        : public SpawnObject
{
public:
    virtual ~Enemy() override = default;

    virtual void init() override;

public slots:
    virtual void move() override final;

protected:
    Enemy(QGraphicsScene *scene);

    void setHitpoint(int hitpoint);

private:
    virtual void setHitpoint() = 0;

    void findCollision(Gunshell *gunshell);

private:
    int hitpoint_;
};
