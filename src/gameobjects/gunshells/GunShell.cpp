#include "GunShell.h"

GunShell::GunShell(QGraphicsItem *parent)
    : MovableObject(parent)
{

}

void GunShell::init(QGraphicsScene *scene)
{
    MovableObject::init(scene);

    playShotSound();
    setDamage();
}

unsigned int GunShell::getDamage() const
{
    return damage_;
}

void GunShell::move()
{  
    //move gun shell up
    setPos(x(), y() - speed());

    //delete gun shell
    if(y() + pixmap().height() < 0)
    {
        destroyObject(this);
    }
}

unsigned int &GunShell::damage()
{
    return damage_;
}

void GunShell::playShotSound()
{
    QMediaPlayer shotSound;
    shotSound.setMedia(QUrl(pathToSound()));
    shotSound.play();
}
