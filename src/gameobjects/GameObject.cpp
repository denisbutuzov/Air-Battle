#include "GameObject.h"

GameObject::GameObject(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
}

void GameObject::init(QGraphicsScene *scene)
{
    scene->addItem(this);
    setObjectImage();
    setStartObjectPos();
}
