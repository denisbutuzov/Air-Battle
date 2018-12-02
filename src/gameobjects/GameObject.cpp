#include "GameObject.h"

GameObject::GameObject(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{

}

void GameObject::init(QGraphicsScene *scene)
{
    setObjectImage();
    setStartObjectPos();
    scene->addItem(this);
}
