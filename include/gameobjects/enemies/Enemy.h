#pragma once

#include "Gunshell.h"
#include "SpawnObject.h"

class Enemy
        : public SpawnObject
{
public:
    Enemy(QGraphicsItem *parent = nullptr);
    virtual void init(QGraphicsScene *scene) override final;
public slots:
    virtual void move() override final;
protected:
    void setHitpoint(int hitpoint);
private:
    virtual void setHitpoint();
    virtual void setObjectImage() override;
    void findCollision(Gunshell *gunshell);
private:
    int hitpoint_;
};
