#include <QGraphicsScene>

#include "GameObject.h"

GameObject::GameObject(std::weak_ptr<QGraphicsScene> scene)
    :  scene_(scene)
{
}

std::weak_ptr<QGraphicsScene> GameObject::scene() const
{
    return scene_;
}

void GameObject::init()
{
    if(pixmap().isNull())
    {
        qFatal("You must to set a picture");
    }
    if(auto wp = scene_.lock())
    {
        wp->addItem(this);
    }
}
