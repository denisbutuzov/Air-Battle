#include "HandWeapon.h"

HandWeapon::HandWeapon(std::shared_ptr<QGraphicsScene> scene, int delayBetweenShots)
    : scene_(scene)
    , delayBetweenShots_(delayBetweenShots)
    , readyToShoot_(true)
{
    delayBetweenShotsTimer_ = std::make_unique<QTimer>();
    connect(delayBetweenShotsTimer_.get(), SIGNAL(timeout()),
            this, SLOT(setReadyToShoot()));
}

bool HandWeapon::isReadyToShoot() const
{
    return readyToShoot_;
}

std::shared_ptr<QGraphicsScene> HandWeapon::scene()
{
    return scene_;
}

void HandWeapon::startDelayBetweenShotsTimer()
{
    delayBetweenShotsTimer_->start(delayBetweenShots_);
    readyToShoot_ = false;
}

void HandWeapon::setReadyToShoot()
{
    readyToShoot_ = true;
}
