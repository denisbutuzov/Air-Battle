#include <stdlib.h>

#include <QTimer>
#include <QGraphicsScene>

#include "Enemy.h"

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
        scene()->removeItem(this);
        delete this;
    }
}
