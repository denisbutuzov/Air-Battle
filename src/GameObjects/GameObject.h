#pragma once

#include <QGraphicsPixmapItem>

#include <memory>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    virtual ~GameObject() = default;
    virtual void init();
    std::weak_ptr<QGraphicsScene> scene() const;
protected:
    GameObject(std::weak_ptr<QGraphicsScene> scene);
private:
    std::weak_ptr<QGraphicsScene> scene_;
};
