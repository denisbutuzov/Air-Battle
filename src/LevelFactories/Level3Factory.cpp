#include <QGraphicsScene>

#include "GameObjectBuilders/PresetPositionBuilder.h"
#include "GameObjects/Enemies/EnemyDecorators/ShieldDecorator.h"
#include "GameObjects/Weapons/Bazooka.h"

#include "Level3Factory.h"

Level3Factory::Level3Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level3Factory::enemy()
{
    PresetPositionBuilder builder;
    auto enemy = std::make_unique<ShieldDecorator>(builder.buildEnemy(scene(), 6, 1, ":/images/images/Enemy2.png"));
    enemy->setPixmap(QPixmap(":/images/images/EnemyShield.png"));
    enemy->setHitpoint(2);
    return enemy;
}

std::unique_ptr<Weapon> Level3Factory::weapon()
{
    auto weapon = std::make_unique<Bazooka>(scene());
    weapon->setPixmap(QPixmap(":/images/images/bazooka.png"));
    weapon->setSpeed(6);

    int randomNumber = rand() % static_cast<int>(scene()->width() - weapon->pixmap().width());
    weapon->setPos(randomNumber, 0 - weapon->pixmap().height());
    return weapon;
}
