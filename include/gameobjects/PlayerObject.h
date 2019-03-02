#pragma once

#include "GameObject.h"

class HandWeapon;

class PlayerObject
        : public GameObject
{
public:
    PlayerObject(const std::shared_ptr<QGraphicsScene> &scene,
                 std::unique_ptr<HandWeapon> &&weapon);
    virtual ~PlayerObject() override;

private:
    virtual void keyPressEvent(QKeyEvent *event) override final;

    void shoot() const;
    void stepToLeft();
    void stepToRight();

private:
    std::unique_ptr<HandWeapon> weapon_;
};
