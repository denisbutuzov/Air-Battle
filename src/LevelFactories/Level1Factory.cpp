#include "GameObjects/Enemies/Enemy.h"

#include "Level1Factory.h"

constexpr const char *ENEMY_IMAGE = ":/images/images/Enemy1.png";

Level1Factory::Level1Factory(std::weak_ptr<QGraphicsScene> scene)
    : AbstractLevelFactory(scene)
{
}

std::unique_ptr<Enemy> Level1Factory::enemy()
{
    auto enemy = std::make_unique<Enemy>(scene());
    enemy->setPixmap(QPixmap(ENEMY_IMAGE));
    enemy->setPos(randomPos(enemy->pixmap()));
    return enemy;
}
