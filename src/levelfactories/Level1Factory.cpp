#include <QGraphicsScene>

#include "Enemy.h"

#include "Level1Factory.h"

Level1Factory::Level1Factory(const std::shared_ptr<QGraphicsScene> &scene)
    : AbstractLevelFactory(scene)
{
}

Enemy *Level1Factory::enemy()
{
    auto *enemy = new Enemy(scene());
    enemy->setPixmap(QPixmap(":/images/images/Enemy1.png"));
    enemy->setSpeed(6);
    enemy->setHitpoint(1);
    int randomNumber = rand() % static_cast<int>(scene()->width() - enemy->pixmap().width());
    enemy->setPos(randomNumber, 0 - enemy->pixmap().height());

    return enemy;
}
