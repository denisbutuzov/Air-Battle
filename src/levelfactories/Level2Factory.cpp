#include <QGraphicsScene>

#include "PresetPositionBuilder.h"
#include "Enemy.h"

#include "Level2Factory.h"

Level2Factory::Level2Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level2Factory::enemy()
{
    PresetPositionBuilder builder;
    return builder.buildEnemy(scene(), 6, 1, ":/images/images/Enemy2.png");
}
