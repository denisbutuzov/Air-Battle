#pragma once

class AppSettings
{
public:
    struct Scene
    {
        const char *backGround_;
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
        const char *player_;
        const char *enemy1_;
        const char *enemy2_;
        const char *shield_;
        struct Weapon
        {
            const char *weapon_;
            const char *gunshell_;
            const char *patron_;
            const char *shotSound_;
            const char *reloadSound_;
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
private:
    Scene scene_;
    Time time_;
    Objects objects_;
};
