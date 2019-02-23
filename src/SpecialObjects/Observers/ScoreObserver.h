#pragma once

#include <QGraphicsTextItem>

#include <memory>

#include "AbstractObserver.h"

class Score;

class ScoreObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    ScoreObserver(Score *score);
    virtual void update() override;

    void show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    Score *subject_;
};
