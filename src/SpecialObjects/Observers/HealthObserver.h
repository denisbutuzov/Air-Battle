#pragma once

#include <QQueue>
#include <QPointF>

#include <functional>
#include <memory>

#include "AbstractObserver.h"

class Health;
class QGraphicsScene;
class QGraphicsPixmapItem;

class HealthObserver
        : public AbstractObserver
{
public:
    HealthObserver(Health *health);
    virtual void update() override;

    void show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    void addHeart();
    void removeHeart();
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack);

private:
    Health *subject_;
    QPointF coordinate_;
    std::shared_ptr<QGraphicsScene> scene_;
    QQueue<QGraphicsPixmapItem *> hearts_;
};
