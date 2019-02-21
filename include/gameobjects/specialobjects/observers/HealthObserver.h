#pragma once

#include <QQueue>
#include <QPointF>

#include "functional"

#include "AbstractObserver.h"

class Health;
class HeartObject;
class QGraphicsScene;

class HealthObserver
        : public AbstractObserver
{
public:
    HealthObserver(Health *health);

    virtual void update() override;

    void show(QGraphicsScene *scene, QPointF coordinate = QPointF(0.0, 0.0));
    QPointF coordinate() const;
    const QQueue<HeartObject *> &hearts() const;

private:
    void addHeart();
    void removeHeart();
    void repeatWhileSizesAreNotEqual(std::function<void()> &&callBack);

private:
    Health *subject_;
    QGraphicsScene *scene_;
    QPointF coordinate_;
    QQueue<HeartObject *> hearts_;
};
