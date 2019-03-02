#pragma once

#include <QGraphicsPixmapItem>
#include <memory>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    virtual ~GameObject() = default;
    virtual void init();

protected:
    GameObject(const std::shared_ptr<QGraphicsScene> &scene);

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
