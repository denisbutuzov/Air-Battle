﻿#pragma once

#include "GameObject.h"
#include "MoveStrategies/MoveStrategy.h"

class AbstractVisitor;

class MovableObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    virtual ~MovableObject() override = default;
    virtual void accept(AbstractVisitor &visitor) = 0;
    virtual void move();

    void setSpeed(unsigned int speed);
    unsigned int speed() const;
    std::shared_ptr<MoveStrategy> &moveStrategy();

protected:
    MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                  const std::shared_ptr<MoveStrategy> &moveStrategy);

private:
    std::shared_ptr<MoveStrategy> moveStrategy_;
    unsigned int speed_;
};
