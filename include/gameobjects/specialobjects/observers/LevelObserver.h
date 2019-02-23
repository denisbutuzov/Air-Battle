#pragma once

#include <QGraphicsTextItem>

#include "AbstractObserver.h"

class Level;

class LevelObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    LevelObserver(Level *level);
    virtual void update() override;

    void show(QGraphicsScene *scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    Level *subject_;
};
