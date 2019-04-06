#include <QGraphicsScene>

#include "PresetPositionBuilder.h"
#include "Enemy.h"

#include "Level1Factory.h"

Level1Factory::Level1Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level1Factory::enemy()
{
    PresetPositionBuilder builder;
    return builder.buildEnemy(scene(), 6, 1, ":/images/images/Enemy1.png");
}
