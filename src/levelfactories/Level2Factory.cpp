#include <QGraphicsScene>

#include "PresetPositionBuilder.h"

#include "Level2Factory.h"

Level2Factory::Level2Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level2Factory::enemy()
{
    PresetPositionBuilder builder;
    auto *enemy = builder.buildEnemy(scene(), 6, 1, ":/images/images/Enemy2.png");
    return enemy;
}
