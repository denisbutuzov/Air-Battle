#include <QKeyEvent>
#include <QGraphicsScene>

#include "Bullet.h"

#include "MyRect.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        setPos(x() + 10, y());
    }
    //create a bullet
    else if(event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}
