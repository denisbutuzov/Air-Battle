#include <QMediaPlayer>

#include "GunShell.h"

#include "Enemy.h"

Enemy::Enemy(QGraphicsItem *parent)
    : SpawnObject(parent)
{
    setHitpoint();
}

void Enemy::move()
{
    //find colliding items
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(GunShell *gunshell = dynamic_cast<GunShell *>(colliding_items[i]))
        {
            collision(gunshell);
            return;
        }
    }

    //call move method
    SpawnObject::move();
}

void Enemy::collision(GunShell *gunshell)
{

    if(hitpoint_ - static_cast<int>(gunshell->getDamage()) <= 0)
    {
        //play sound of destroing object
        QMediaPlayer *sound = new QMediaPlayer();
        sound->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
        sound->play();

        //delete object from scene and memory
        destroyObject(this);
    }
    else
    {
        //delete gunshell from scene and memory
        destroyObject(gunshell);
    }
}

void Enemy::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/enemy_plane.png"));
}

void Enemy::setHitpoint()
{
    hitpoint_ = 1;
}




