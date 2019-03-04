#include "AbstractLevelFactory.h"

AbstractLevelFactory::AbstractLevelFactory(const std::shared_ptr<QGraphicsScene> &scene)
    : scene_(scene)
{
}

std::shared_ptr<QGraphicsScene> &AbstractLevelFactory::scene()
{
    return scene_;
}
