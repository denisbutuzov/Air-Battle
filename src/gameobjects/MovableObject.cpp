#include <QGraphicsScene>
#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(QGraphicsScene *scene, MoveStrategy *moveStrategy)
    : GameObject(scene)
    , moveStrategy_(moveStrategy)
{
}

MovableObject::~MovableObject()
{
    delete moveObjectTimer_;
    delete moveStrategy_;
}

void MovableObject::init()
{
    //call basic method show
    GameObject::init();

    //set speed of object
    setSpeed();

    //connect
    moveObjectTimer_ = new QTimer(this);
    connect(moveObjectTimer_, SIGNAL(timeout()), this, SLOT(move()));

    moveObjectTimer_->start(50);
}

unsigned int MovableObject::speed() const
{
    return speed_;
}

MoveStrategy *MovableObject::moveStrategy() const
{
    return moveStrategy_;
}

void MovableObject::move()
{
    moveStrategy_->move(this);

    auto location = checkOnBackstage(moveStrategy_->direction());
    if(location == LOCATION::BEHIND_SCENE)
    {
        OnLeaveFromScene();
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(auto *otherObject = dynamic_cast<GameObject *>(colliding_items[i]))
        {
            OnMeetOtherObject(otherObject);
        }
    }
}

void MovableObject::OnLeaveFromScene()
{
    destroy(this);
}

void MovableObject::destroy(GameObject *object)
{
    scene()->removeItem(object);
    delete object;
}

void MovableObject::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

void MovableObject::setSpeed()
{
    setSpeed(5);
}

MovableObject::LOCATION MovableObject::checkOnBackstage(MoveStrategy::DIRECTION dir)
{
    if(dir == MoveStrategy::DIRECTION::DOWN)
    {
        if(y() > scene()->height())
        {
            return LOCATION::BEHIND_SCENE;
        }
    }
    else
    {
        if(y() + pixmap().height() < 0)
        {
            return LOCATION::BEHIND_SCENE;
        }
    }

    return LOCATION::ON_SCENE;
}
