#pragma once

#include <memory>

class QGraphicsScene;
class Enemy;
class Weapon;

class AbstractLevelFactory
{
public:
    virtual ~AbstractLevelFactory() = default;
    virtual std::unique_ptr<Enemy> enemy() = 0;
    virtual std::unique_ptr<Weapon> weapon() = 0;

protected:
    AbstractLevelFactory(const std::shared_ptr<QGraphicsScene> &scene);

    std::shared_ptr<QGraphicsScene> &scene();

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
