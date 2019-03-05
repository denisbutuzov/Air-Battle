#include <QGraphicsScene>

#include "PresetPositionBuilder.h"

#include "Level1Factory.h"

Level1Factory::Level1Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level1Factory::enemy()
{
    PresetPositionBuilder builder;
    auto *enemy = builder.buildEnemy(scene(), 6, 1, ":/images/images/Enemy1.png");
    return enemy;
}
