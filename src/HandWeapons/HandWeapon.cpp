#include <QTimer>

#include "GameObjects/Gunshells/Gunshell.h"

#include "HandWeapon.h"

HandWeapon::HandWeapon(std::weak_ptr<QGraphicsScene> scene, unsigned int capacity,
                       unsigned int patrons, unsigned int shotDelay, const char *shotSound)
    : scene_(scene)
    , capacity_(capacity)
    , shotSound_(shotSound)
    , shotDelay_(shotDelay)    
    , shotDelayIsActive_(false)
{
    addPatrons(patrons);
    reload();
    shotSoundPlayer_.setMedia(QUrl(shotSound_));
}

bool HandWeapon::unlimitedPatrons() const
{
    return false;
}

unsigned int HandWeapon::patronsInMagazine() const
{
    return patrons_.inMagazine;
}

unsigned int HandWeapon::patronsInStorage() const
{
    return patrons_.inStorage;
}

unsigned int HandWeapon::capacity() const
{
    return capacity_;
}

std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    if((unlimitedPatrons() || (patronsInMagazine() > 0) ) && !shotDelayIsActive_)
    {
        QTimer::singleShot(shotDelay_, [&](){ shotDelayIsActive_ = false; });
        shotDelayIsActive_ = true;
        if(patrons_.inMagazine > 0)
        {
            --patrons_.inMagazine;
        }
        playShotSound();
        return createGunshell(x, y);
    }
    return std::unique_ptr<Gunshell>();
}

std::weak_ptr<QGraphicsScene> HandWeapon::scene() const
{
    return scene_;
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
    if(patrons_.inStorage > 0 && patrons_.inMagazine < capacity_)
    {
        auto requiredPatrons = capacity_ - patrons_.inMagazine;
        if(patrons_.inStorage >= requiredPatrons)
        {
            patrons_.inStorage -= requiredPatrons;
            patrons_.inMagazine += requiredPatrons;
        }
        else
        {
            patrons_.inMagazine += patrons_.inStorage;
            patrons_.inStorage = 0;
        }
    }
}

void HandWeapon::addPatrons(unsigned int patrons)
{
    patrons_.inStorage += patrons;
}
