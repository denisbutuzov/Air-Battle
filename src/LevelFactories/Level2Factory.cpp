#include <QGraphicsScene>

#include "PresetPositionBuilder.h"
#include "Enemy.h"
#include "Bazooka.h"

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

std::unique_ptr<Weapon> Level2Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(":/images/images/bazooka.png"));
    weapon->setSpeed(6);

    int randomNumber = rand() % static_cast<int>(scene()->width() - weapon->pixmap().width());
    weapon->setPos(randomNumber, 0 - weapon->pixmap().height());
    return weapon;
}
