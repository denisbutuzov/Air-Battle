#include "GameObject.h"

GameObject::GameObject(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{

}

void GameObject::show(QGraphicsScene *scene)
{
    setObjectImage();
    setStartObjectPos();
    scene->addItem(this);
}
