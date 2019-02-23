#pragma once

#include <QGraphicsTextItem>

#include "AbstractObserver.h"

class Score;

class ScoreObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    ScoreObserver(Score *score);
    virtual void update() override;

    void show(QGraphicsScene *scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    Score *subject_;
};
