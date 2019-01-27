#pragma once

#include "HandWeapon.h"
#include "GameObject.h"

class PlayerObject
        : public GameObject
{
public:
    PlayerObject(QGraphicsScene *scene);
    virtual ~PlayerObject() override;

    void takeWeapon(HandWeapon *weapon);

protected:
    void keyPressEvent(QKeyEvent *event) override final;

private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;

    void shoot() const;

private:
    HandWeapon *weapon_;
};
