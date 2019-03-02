#include <QGraphicsScene>
#include <QTimer>

#include "MovableObject.h"

MovableObject::MovableObject(const std::shared_ptr<QGraphicsScene> &scene,
                             std::unique_ptr<MoveStrategy> &&moveStrategy)
    : GameObject(scene)
    , moveStrategy_(std::move(moveStrategy))
{
}

MovableObject::~MovableObject() = default;

void MovableObject::init()
{
    //call basic method init()
    GameObject::init();

    //connect
    moveTimer_ = std::make_unique<QTimer>();
    connect(moveTimer_.get(), SIGNAL(timeout()),
            this, SLOT(move()));

    moveTimer_->start(50);
}

void MovableObject::destroy()
{
    scene()->removeItem(this);
    delete this;
}

void MovableObject::setSpeed(unsigned int speed)
{
    speed_ = speed;
}

unsigned int MovableObject::speed() const
{
    return speed_;
}

void MovableObject::move()
{
    moveStrategy_->move(*this);

    auto location = checkOnBackstage(moveStrategy_->direction());
    if(location == LOCATION::BEHIND_SCENE)
    {
        onLeaveFromScene();
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(auto *otherObject = dynamic_cast<GameObject *>(colliding_items[i]))
        {
            onMeetOtherObject(otherObject);
        }
    }
}

void MovableObject::onLeaveFromScene()
{
    destroy();
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





