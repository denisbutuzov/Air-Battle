#include <QGraphicsScene>

#include "GameObject.h"

GameObject::GameObject(std::shared_ptr<QGraphicsScene> scene,
                       const QString &pixmap)
    :  scene_(scene)
{
    setPixmap(QPixmap(pixmap));
}

std::shared_ptr<QGraphicsScene> GameObject::scene() const
{
    return scene_;
}

void GameObject::init()
{
    scene_->addItem(this);
}
