#include <QGraphicsScene>

#include "GameObject.h"

GameObject::GameObject(const std::shared_ptr<QGraphicsScene> &scene)
    :  scene_(scene)
{
}

void GameObject::init()
{
    scene_->addItem(this);
}
