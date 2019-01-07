#include <QMediaPlayer>

#include "Gunshell.h"

#include "Enemy.h"

Enemy::Enemy(QGraphicsItem *parent)
    : SpawnObject(parent)
{
}

void Enemy::init(QGraphicsScene *scene)
{
    SpawnObject::init(scene);
    setHitpoint();
}

void Enemy::move()
{
    SpawnObject::move();

    //find colliding items
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(Gunshell *gunshell = dynamic_cast<Gunshell *>(colliding_items[i]))
        {
            findCollision(gunshell);
        }
    }
}

void Enemy::setHitpoint(int hitpoint)
{
    hitpoint_ = hitpoint;
}

void Enemy::setHitpoint()
{
    setHitpoint(2);
}
void Enemy::findCollision(Gunshell *gunshell)
{
    hitpoint_ -= static_cast<int>(gunshell->damage());
    if(hitpoint_ <= 0)
    {
        //play sound of destroing object
        QMediaPlayer *sound = new QMediaPlayer();
        sound->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
        sound->play();

        //delete object from scene and memory
        destroy(gunshell);
        destroy();
    }
    else
    {
        //delete gunshell from scene and memory
        destroy(gunshell);
    }
}

void Enemy::setObjectImage()
{
    setPixmap(QPixmap(":/images/images/Enemy2.png"));
}




