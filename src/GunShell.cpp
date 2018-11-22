#include <QTimer>
#include <QGraphicsScene>

#include "GunShell.h"

void GunShell::loadSettings()
{
    //set speed of gun shell
    setSpeed();

    //set sound of shot
    setShotSound();

    //set image of gun shell
    setPixmap();

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);
}

unsigned int &GunShell::speed()
{
    return speed_;
}

QMediaPlayer &GunShell::shotSound()
{
    return shotSound_;
}

void GunShell::move()
{
    //move gun shell up
    setPos(x(), y() - speed_);

    //delete gun shell
    if(y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
