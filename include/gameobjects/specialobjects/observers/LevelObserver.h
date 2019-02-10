#pragma once

#include <QGraphicsTextItem>

#include "Level.h"
#include "AbstractObserver.h"

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
