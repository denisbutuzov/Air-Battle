#pragma once

#include <QGraphicsTextItem>

#include <memory>

#include "AbstractObserver.h"

class Level;

class LevelObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    LevelObserver(Level *level);
    virtual void update() override;

    void show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    Level *subject_;
};
