#pragma once

#include "GameObject.h"

class PlayerObject
        : public GameObject
{
public:
    PlayerObject(QGraphicsItem *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override final;
};
