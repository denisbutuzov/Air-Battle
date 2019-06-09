#pragma once

#include "GameObject.h"

class AbstractVisitor;
class MoveStrategy;

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
    std::shared_ptr<MoveStrategy> moveStrategy() const;
protected:
    MovableObject(std::weak_ptr<QGraphicsScene> scene,
                  std::shared_ptr<MoveStrategy> moveStrategy);
private:
    std::shared_ptr<MoveStrategy> moveStrategy_;
};
