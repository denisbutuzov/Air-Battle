#pragma once

#include "Weapon.h"
#include "IHandWeapon.h"
#include "GameObject.h"

class PlayerObject
        : public GameObject
{
public:
    PlayerObject(QGraphicsItem *parent = nullptr);
    void takeWeapon(IHandWeapon *weapon);
protected:
    void keyPressEvent(QKeyEvent *event) override final;
private:
    void shoot();
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;
private:
    IHandWeapon *weapon_;
};
