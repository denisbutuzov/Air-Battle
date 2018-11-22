#include <QTimer>
#include <QGraphicsScene>

#include "Enemy.h"

#include "GunShell.h"

void GunShell::loadGunShellSettings()
{
    //set speed of gun shell
    setGunShellSpeed();

    //set sound of shot
    setShotSound();

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(20);
}

void GunShell::move()
{
    //move gun shell up
    setPos(x(), y() - gunShellSpeed_);

    //delete gun shell
    if(y() + pixmap().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
