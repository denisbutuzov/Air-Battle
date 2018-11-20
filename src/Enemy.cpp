#include <stdlib.h>

#include <QTimer>
#include <QGraphicsScene>

#include "Game.h"

#include "Enemy.h"

extern Game *game;

Enemy::Enemy()
{
    //set random position of enemy
    int random_number = rand() % 700;
    setPos(random_number, 0);

    //drew the enemy
    setRect(0, 0, 100, 100);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
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
