#include <QTimer>
#include <QGraphicsScene>

#include "Enemy.h"
#include "Game.h"

#include "Bullet.h"

extern Game *game;

Bullet::Bullet()
{
    //draw graphics
    setPixmap(QPixmap(":/images/images/bullet.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

    boomsound_ = new QMediaPlayer();
    boomsound_->setMedia(QUrl("qrc:/sounds/sounds/boom.wav"));
}

void Bullet::move()
{
    //destroy enemy and bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //play destroy sound
            if(boomsound_->state() == QMediaPlayer::PlayingState)
            {
                boomsound_->setPosition(0);
            }
            else if(boomsound_->state() == QMediaPlayer::StoppedState)
            {
                boomsound_->play();
            }

            //increase the score
            game->score_->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    //move bullet up
    setPos(x(), y() - 10);

    //delete bullet
    if(y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
