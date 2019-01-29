#include "GameObject.h"

GameObject::GameObject(QGraphicsScene *scene)
    :  scene_(scene)
{
}

void GameObject::init()
{
    scene_->addItem(this);

    setObjectImage();
    setStartObjectPos();
}
