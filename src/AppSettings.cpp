#include "AppSettings.h"

AppSettings &AppSettings::instance()
{
    static AppSettings appSettings;
    return appSettings;
}

const AppSettings::Scene &AppSettings::scene() const
{
    return scene_;
}

const AppSettings::Time &AppSettings::time() const
{
    return time_;
}

const AppSettings::Objects &AppSettings::objects() const
{
    return objects_;
}

AppSettings::AppSettings()
{
    scene_.backGround_ = ":/images/images/Space.jpg";
    scene_.height_ = 800;
    scene_.width_ = 600;

    time_.spawnObjectPeriod_ = 2000;
    time_.removeObjectPeriod_ = 50;
    time_.moveObjectPeriod_ = 50;
    time_.checkCollisionPeriod_ = 50;
    time_.levelChangePeriod_ = 10000;

    objects_.player_ = ":/images/images/Player.png";
    objects_.enemy1_ = ":/images/images/Enemy1.png";
    objects_.enemy2_ = ":/images/images/Enemy2.png";
    objects_.shield_ = ":/images/images/EnemyShield.png";

    objects_.gun_.weapon_ = nullptr;
    objects_.gun_.gunshell_ = ":/images/images/Gun_gunshell.png";
    objects_.gun_.patron_ = nullptr;
    objects_.gun_.shotSound_ = "qrc:/sounds/sounds/bullet.wav";
    objects_.gun_.reloadSound_ = "qrc:/sounds/sounds/reload.aiff";
    objects_.gun_.capacity_ = 0;
    objects_.gun_.startPatrons_ = 0;
    objects_.gun_.shotDelay_ = 100;
    objects_.gun_.reloadDelay_ = 800;

    objects_.machinegun_.weapon_ = ":/images/images/Machinegun.png";
    objects_.machinegun_.gunshell_ = ":/images/images/Machinegun_gunshell.png";
    objects_.machinegun_.patron_ = ":/images/images/Machinegun_patron.png";
    objects_.machinegun_.shotSound_ = "qrc:/sounds/sounds/bullet.wav";
    objects_.machinegun_.reloadSound_ = "qrc:/sounds/sounds/reload.aiff";
    objects_.machinegun_.capacity_ = 12;
    objects_.machinegun_.startPatrons_ = 24;
    objects_.machinegun_.shotDelay_ = 50;
    objects_.machinegun_.reloadDelay_ = 800;

    objects_.bazooka_.weapon_ = ":/images/images/Bazooka.png";
    objects_.bazooka_.gunshell_ = ":/images/images/Bazooka_gunshell.png";
    objects_.bazooka_.patron_ = ":/images/images/Bazooka_patron.png";
    objects_.bazooka_.shotSound_ = "qrc:/sounds/sounds/boom.wav";
    objects_.bazooka_.reloadSound_ = "qrc:/sounds/sounds/reload.aiff";
    objects_.bazooka_.capacity_ = 5;
    objects_.bazooka_.startPatrons_ = 5;
    objects_.bazooka_.shotDelay_ = 500;
    objects_.bazooka_.reloadDelay_ = 800;
}
