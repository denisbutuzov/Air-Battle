#include <QTimer>

#include "GameObjects/Gunshells/Gunshell.h"

#include "HandWeapon.h"

HandWeapon::HandWeapon(std::weak_ptr<QGraphicsScene> scene, int capacity,
                       int patrons, int shotDelay, const char *shotSound)
    : scene_(scene)
    , capacity_(capacity)
    , shotDelay_(shotDelay)
    , shotSound_(shotSound)
{
    addPatrons(patrons);
    reload();
    shotSoundPlayer_.setMedia(QUrl(shotSound_));
}

std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    static int shotDelayIsActive = false;

    if(patronsExist() && !shotDelayIsActive)
    {
        QTimer::singleShot(shotDelay_, this, [](){ shotDelayIsActive = false ;});
        shotDelayIsActive = true;
        --patrons_.second;
        playShotSound();
        return createGunshell(x, y);
    }
    return std::unique_ptr<Gunshell>();
}

std::weak_ptr<QGraphicsScene> HandWeapon::scene() const
{
    return scene_;
}

bool HandWeapon::patronsExist() const
{
    return patrons_.second;
}

void HandWeapon::playShotSound()
{
    if(shotSoundPlayer_.state() == QMediaPlayer::PlayingState)
    {
        shotSoundPlayer_.setPosition(0);
    }
    else
    {
        shotSoundPlayer_.play();
    }
}

void HandWeapon::reload()
{
    if(patrons_.first > 0 && patrons_.second < capacity_)
    {
        auto requiredPatrons = capacity_ - patrons_.second;
        if(patrons_.first >= requiredPatrons)
        {
            patrons_.first -= requiredPatrons;
            patrons_.second += requiredPatrons;
        }
        else
        {
            patrons_.second += patrons_.first;
            patrons_.first = 0;
        }
    }
}

void HandWeapon::addPatrons(int patrons)
{
    patrons_.first += patrons;
}
