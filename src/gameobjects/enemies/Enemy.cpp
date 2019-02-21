#include <QGraphicsScene>
#include <QMediaPlayer>

#include <typeinfo>

#include "AbstractEnemyDecorator.h"
#include "Gunshell.h"
#include "Score.h"
#include "Health.h"
#include "PlayerObject.h"

#include "Enemy.h"

Enemy::Enemy(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : SpawnObject(scene, moveStrategy)
{
}

void Enemy::init()
{
    SpawnObject::init();
    setHitpoint();
}

void Enemy::setHitpoint(int hitpoint)
{
    hitpoint_ = hitpoint;
}

void Enemy::OnMeetOtherObject(GameObject *otherObject)
{
    if(auto *gunshell = dynamic_cast<Gunshell *>(otherObject))
    {
        onMeetGunshell(gunshell);
    }
    else if(auto *player = dynamic_cast<PlayerObject *>(otherObject))
    {
        onMeetPlayer(player);
    }
}

void Enemy::onMeetPlayer(PlayerObject *player)
{

}

void Enemy::onMeetGunshell(Gunshell *gunshell)
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
        destroy(this);
    }
    else
    {
        //delete gunshell from scene and memory
        destroy(gunshell);
    }
}

void Enemy::OnLeaveFromScene()
{
    Health::instance()->decrease();
    MovableObject::OnLeaveFromScene();
}




