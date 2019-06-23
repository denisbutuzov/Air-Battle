#include <QFile>
#include <QJsonDocument>

#include "AppSettings.h"

constexpr const char *SETTINGS_FILE = ":/settings/settings.json";

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
    load();
}

void AppSettings::load()
{
    QFile settingsFile(SETTINGS_FILE);
    if(!settingsFile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qFatal("Can't load file with settings");
    }

    auto jsonData = settingsFile.readAll();
    QJsonDocument settingsDoc(QJsonDocument::fromJson(jsonData));

    auto &sceneData = settingsDoc["scene"];
    scene_.backGround_ = sceneData["background_image"].toString();
    scene_.height_ = sceneData["height"].toInt();
    scene_.width_ = sceneData["width"].toInt();

    auto &timeData = settingsDoc["time"];
    time_.spawnObjectPeriod_ = timeData["spawn_object_period"].toInt();
    time_.removeObjectPeriod_ = timeData["remove_object_period"].toInt();
    time_.moveObjectPeriod_ = timeData["move_object_period"].toInt();
    time_.checkCollisionPeriod_ = timeData["check_collision_period"].toInt();
    time_.levelChangePeriod_ = timeData["level_change_period"].toInt();

    auto &objectsData = settingsDoc["objects"];
    objects_.player_ = objectsData["player"].toString();
    objects_.enemy1_ = objectsData["enemy1"].toString();
    objects_.enemy2_ = objectsData["enemy2"].toString();
    objects_.shield_ = objectsData["shield"].toString();

    auto &gunData = objectsData["weapons"]["gun"];
    objects_.gun_.weapon_ = gunData["weapon_image"].toString();
    objects_.gun_.gunshell_ = gunData["gunshell_image"].toString();
    objects_.gun_.patron_ = gunData["patron_image"].toString();
    objects_.gun_.shotSound_ = gunData["shot_sound"].toString();
    objects_.gun_.reloadSound_ = gunData["reload_sound"].toString();
    objects_.gun_.capacity_ = static_cast<unsigned int>(gunData["capacity_image"].toInt());
    objects_.gun_.startPatrons_ = static_cast<unsigned int>(gunData["start_patrons"].toInt());
    objects_.gun_.shotDelay_ = static_cast<unsigned int>(gunData["shot_delay"].toInt());
    objects_.gun_.reloadDelay_ = static_cast<unsigned int>(gunData["reload_delay"].toInt());

    auto &machinegunData = objectsData["weapons"]["machinegun"];
    objects_.machinegun_.weapon_ = machinegunData["weapon_image"].toString();
    objects_.machinegun_.gunshell_ = machinegunData["gunshell_image"].toString();
    objects_.machinegun_.patron_ = machinegunData["patron_image"].toString();
    objects_.machinegun_.shotSound_ = machinegunData["shot_sound"].toString();
    objects_.machinegun_.reloadSound_ = machinegunData["reload_sound"].toString();
    objects_.machinegun_.capacity_ = static_cast<unsigned int>(machinegunData["capacity_image"].toInt());
    objects_.machinegun_.startPatrons_ = static_cast<unsigned int>(machinegunData["start_patrons"].toInt());
    objects_.machinegun_.shotDelay_ = static_cast<unsigned int>(machinegunData["shot_delay"].toInt());
    objects_.machinegun_.reloadDelay_ = static_cast<unsigned int>(machinegunData["reload_delay"].toInt());

    auto &bazookaData = objectsData["weapons"]["bazooka"];
    objects_.bazooka_.weapon_ = bazookaData["weapon_image"].toString();
    objects_.bazooka_.gunshell_ = bazookaData["gunshell_image"].toString();
    objects_.bazooka_.patron_ = bazookaData["patron_image"].toString();
    objects_.bazooka_.shotSound_ = bazookaData["shot_sound"].toString();
    objects_.bazooka_.reloadSound_ = bazookaData["reload_sound"].toString();
    objects_.bazooka_.capacity_ = static_cast<unsigned int>(bazookaData["capacity_image"].toInt());
    objects_.bazooka_.startPatrons_ = static_cast<unsigned int>(bazookaData["start_patrons"].toInt());
    objects_.bazooka_.shotDelay_ = static_cast<unsigned int>(bazookaData["shot_delay"].toInt());
    objects_.bazooka_.reloadDelay_ = static_cast<unsigned int>(bazookaData["reload_delay"].toInt());
}
