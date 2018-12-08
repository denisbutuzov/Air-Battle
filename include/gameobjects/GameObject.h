#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    GameObject(QGraphicsItem *parent = nullptr);
    virtual void init(QGraphicsScene *scene);
private:
    virtual void setObjectImage() = 0;
    virtual void setStartObjectPos() = 0;
};
