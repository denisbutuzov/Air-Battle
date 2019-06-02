#pragma once

#include <QGraphicsPixmapItem>

#include <memory>

class GameObject
        : public QGraphicsPixmapItem
{
public:
    virtual ~GameObject() = default;
    virtual void init();

    std::shared_ptr<QGraphicsScene> scene() const;

protected:
    GameObject(std::shared_ptr<QGraphicsScene> scene,
               const QString &pixmap);

private:
    std::shared_ptr<QGraphicsScene> scene_;
};
