#pragma once

#include <QQueue>

#include "HeartObject.h"

const int MAX_HEARTS_NUMBER = 5;

class Health
{
public:
    static Health *instance();
    void show(QGraphicsScene *scene, QPointF coordinate = QPointF(0.0, 0.0));
    void increase();
    void decrease();
    QPointF coordinate() const;
    const QQueue<HeartObject *> &hearts() const;

protected:
    Health();
    Health(const Health &other) = delete;
    Health(Health &&other) = delete;

    Health &operator=(const Health &other) = delete;

private:
    void addHeart();

private:
    static Health *instance_;
    QQueue<HeartObject *> hearts_;
    const int maxHeartsNumber_;
    QGraphicsScene *scene_;
    QPointF coordinate_;
};
