#pragma once

#include <memory>

class QGraphicsScene;
class Enemy;
class Weapon;
class QPointF;
class QPixmap;

class AbstractLevelFactory
{
public:
    virtual ~AbstractLevelFactory() = default;
    virtual std::unique_ptr<Enemy> enemy() = 0;
    virtual std::unique_ptr<Weapon> weapon() = 0;

protected:
    AbstractLevelFactory(std::shared_ptr<QGraphicsScene> scene);

    std::shared_ptr<QGraphicsScene> scene();
    QPointF randomPos(const QPixmap &pixmap);

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
