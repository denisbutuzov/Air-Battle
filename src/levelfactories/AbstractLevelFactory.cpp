#include "AbstractLevelFactory.h"

AbstractLevelFactory::AbstractLevelFactory(QGraphicsScene *scene)
    : scene_(scene)
{
}

QGraphicsScene *AbstractLevelFactory::scene() const
{
    return scene_;
}
