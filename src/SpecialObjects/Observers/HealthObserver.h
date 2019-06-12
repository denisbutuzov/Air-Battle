#pragma once

#include <QPointF>

#include <functional>
#include <memory>
#include <queue>

#include "AbstractObserver.h"

class Health;
class QGraphicsScene;
class QGraphicsPixmapItem;

class HealthObserver
        : public AbstractObserver
{
public:
    HealthObserver(std::weak_ptr<Health> health);
    virtual void update() override;
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    void addHeart();
    void removeHeart();
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack, int value);
private:
    std::weak_ptr<Health> subject_;
    QPointF coordinate_;
    std::weak_ptr<QGraphicsScene> scene_;
    std::queue<std::unique_ptr<QGraphicsPixmapItem>> hearts_;
};
