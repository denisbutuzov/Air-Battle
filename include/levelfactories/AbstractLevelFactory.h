#pragma once

#include "Enemy.h"
#include "Weapon.h"

class AbstractLevelFactory
{
public:
    virtual ~AbstractLevelFactory() = default;

    virtual Enemy *enemy() const = 0;
    virtual Weapon *weapon() const = 0;

protected:
    AbstractLevelFactory(QGraphicsScene *scene);

    QGraphicsScene *scene() const;

private:
    QGraphicsScene *scene_;
};
