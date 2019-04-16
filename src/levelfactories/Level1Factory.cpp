#include <QGraphicsScene>

#include "PresetPositionBuilder.h"
#include "Enemy.h"
#include "Machinegun.h"

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

std::unique_ptr<Weapon> Level1Factory::weapon()
{
    auto weapon = std::make_unique<Machinegun>(scene());
    weapon->setPixmap(QPixmap(":/images/images/machinegun.png"));
    weapon->setSpeed(6);

    int randomNumber = rand() % static_cast<int>(scene()->width() - weapon->pixmap().width());
    weapon->setPos(randomNumber, 0 - weapon->pixmap().height());
    return weapon;
}
