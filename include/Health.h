#pragma once

#include <QQueue>

#include "HeartObject.h"

const int MAX_HEARTS_NUMBER = 5;

class Health
{
public:
    Health(QGraphicsScene *scene, QPointF coordinate);
    ~Health() = default;

    void increase();
    void decrease();
    QPointF coordinate() const;
    const QQueue<HeartObject *> &hearts() const;

private:
    void addHeart();

private:
    QQueue<HeartObject *> hearts_;
    const int maxHeartsNumber_;
    QGraphicsScene *scene_;
    QPointF coordinate_;
};
