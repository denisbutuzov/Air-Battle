#pragma once

#include <QString>

class AppSettings
{
public:
    struct Scene
    {
        QString backGround_;
        int width_;
        int height_;
    };
    struct Time
    {
        int spawnObjectPeriod_;
        int removeObjectPeriod_;
        int moveObjectPeriod_;
        int checkCollisionPeriod_;
        int levelChangePeriod_;
    };
    struct Objects
    {
        QString player_;
        QString enemy1_;
        QString enemy2_;
        QString shield_;
        struct Weapon
        {
            QString weapon_;
            QString gunshell_;
            QString patron_;
            QString shotSound_;
            QString reloadSound_;
            unsigned int capacity_;
            unsigned int startPatrons_;
            unsigned int shotDelay_;
            unsigned int reloadDelay_;
        } gun_, machinegun_, bazooka_;
    };
public:
    static AppSettings &instance();
    const Scene &scene() const;
    const Time &time() const;
    const Objects &objects() const;
private:
    AppSettings();
    ~AppSettings() = default;
    AppSettings(const AppSettings &other) = delete;
    AppSettings &operator=(const AppSettings &other) = delete;
    void load();
private:
    Scene scene_;
    Time time_;
    Objects objects_;
};
