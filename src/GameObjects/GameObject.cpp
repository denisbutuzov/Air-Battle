#include <QGraphicsScene>

#include "GameObject.h"

GameObject::GameObject(const std::shared_ptr<QGraphicsScene> &scene)
    :  scene_(scene)
{
}

std::shared_ptr<QGraphicsScene> GameObject::scene() const
{
    return scene_;
}

void GameObject::init()
{
    scene_->addItem(this);
}
