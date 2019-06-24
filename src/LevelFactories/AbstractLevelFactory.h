#pragma once

#include <memory>

class QGraphicsScene;
class Enemy;
class Bonus;
class Weapon;
class QPointF;
class QPixmap;

class AbstractLevelFactory
{
public:
    virtual ~AbstractLevelFactory() = default;
    virtual std::unique_ptr<Enemy> enemy() = 0;
    virtual std::unique_ptr<Weapon> weapon() = 0;
    virtual std::unique_ptr<Bonus> bonus();
protected:
    AbstractLevelFactory(std::weak_ptr<QGraphicsScene> scene);
    std::weak_ptr<QGraphicsScene> scene() const;
    QPointF randomPos(const QPixmap &pixmap);
private:
    std::weak_ptr<QGraphicsScene> scene_;
};
