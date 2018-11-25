#include "GameObject.h"

GameObject::GameObject(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{

}

void GameObject::draw(QGraphicsScene *scene)
{
    setObjectImage();
    setObjectPos();
    scene->addItem(this);
}
