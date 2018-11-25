#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    GameObject(QGraphicsItem *parent = nullptr);
    virtual ~GameObject() = default;
    virtual void draw(QGraphicsScene *scene);
private:
    virtual void setObjectImage() = 0;
    virtual void setObjectPos() = 0;
};
