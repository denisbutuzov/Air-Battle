#include <cstdlib>

#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>

#include "Game.h"
#include "Bullet.h"
#include "Rocket.h"

#include "Enemy.h"

extern Game *game;

Enemy::Enemy()
{
    //draw player
    setPixmap(QPixmap(":/images/images/enemy_plane.png"));

    //set random position of enemy
    int random_number = rand() % 700;
    setPos(random_number, 0 - pixmap().height());

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //destroy enemy and gun shell
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if((typeid(*(colliding_items[i])) == typeid(Bullet)) || (typeid(*(colliding_items[i])) == typeid(Rocket)))
        {
            QMediaPlayer *destroySound = new QMediaPlayer();
            destroySound->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
            destroySound->play();

            //remove them both from scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    //move enemy down
    setPos(x(), y() + 5);

    //delete enemy
    if(y() > scene()->height())
    {
        //decrease the health
        game->health_->decrease();

        //remove from the scene
        scene()->removeItem(this);
        delete this;
    }
}
