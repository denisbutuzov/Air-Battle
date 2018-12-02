#pragma once

#include <QMediaPlayer>

#include "MovableObject.h"

class GunShell
        : public MovableObject
{
public:
    GunShell(QGraphicsItem *parent = nullptr);
    virtual void init(QGraphicsScene *scene) override final;
    unsigned int getDamage() const;
public slots:
    virtual void move() override final;
protected:
    unsigned int &damage();
private:
    void playShotSound();
    virtual void setDamage() = 0;
    virtual QString pathToSound() = 0;
private:
    unsigned int damage_;
};
