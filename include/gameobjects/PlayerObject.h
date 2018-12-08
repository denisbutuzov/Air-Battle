#pragma once

#include "GameObject.h"

class PlayerObject
        : public GameObject
{
public:
    PlayerObject(QGraphicsItem *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event) override final;
private:
    virtual void setObjectImage() override final;
    virtual void setStartObjectPos() override final;
};
