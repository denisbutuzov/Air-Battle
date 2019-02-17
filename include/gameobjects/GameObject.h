#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    virtual ~GameObject() = default;
    virtual void init();

protected:
    GameObject(QGraphicsScene *scene);

private:
    virtual void setObjectImage() = 0;
    virtual void setStartObjectPos() = 0;

private:
    QGraphicsScene *scene_;
};
