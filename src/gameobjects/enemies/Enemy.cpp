#include <QGraphicsScene>
#include <QMediaPlayer>

#include "AbstractEnemyDecorator.h"
#include "Gunshell.h"
#include "Score.h"
#include "Health.h"

#include "Enemy.h"

Enemy::Enemy(QGraphicsScene *scene)
    : SpawnObject(scene)
{
}

void Enemy::init()
{
    SpawnObject::init();
    setHitpoint();
}

void Enemy::move()
{
    //move object down
    setPos(x(), y() + speed());

    //delete object when it is behind the scene
    if(y() > scene()->height())
    {
        //remove from the scene and memory
        Health::instance()->decrease();
        destroy();
    }

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

void Enemy::findCollision(Gunshell *gunshell)
{
    hitpoint_ -= static_cast<int>(gunshell->damage());
    if(hitpoint_ <= 0)
    {
        if(Enemy *enemy = dynamic_cast<AbstractEnemyDecorator *>(this))
        {
            //play sound of destroing object
            QMediaPlayer *sound = new QMediaPlayer();
            sound->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
            sound->play();
        }
        else
        {
            Score::instance()->increase();
            QMediaPlayer *sound = new QMediaPlayer();
            sound->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
            sound->play();
        }

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




