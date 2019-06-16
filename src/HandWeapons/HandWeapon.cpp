#include <QTimer>

#include "GameObjects/Gunshells/Gunshell.h"

#include "HandWeapon.h"

constexpr unsigned int HANDWEAPON_RELOAD_DELAY_MS = 800;
constexpr const char *HANDWEAPON_RELOAD_SOUND = "qrc:/sounds/sounds/reload.aiff";

HandWeapon::HandWeapon(std::weak_ptr<QGraphicsScene> scene, unsigned int capacity,
                       unsigned int patrons, unsigned int shotDelay, const char *shotSound)
    : scene_(scene)
    , magazine_(capacity, 0)
    , patrons_(patrons)
    , shotSound_(shotSound)
    , shotDelay_(shotDelay)
    , shotDelayIsActive_(false)
    , reloadDelay_(HANDWEAPON_RELOAD_DELAY_MS)
    , reloadDelayIsActive_(false)
{
    loadMagazine();
}

bool HandWeapon::unlimitedPatrons() const
{
    return false;
}

unsigned int HandWeapon::patronsInMagazine() const
{
    return magazine_.patrons;
}

unsigned int HandWeapon::patronsInStorage() const
{
    return patrons_;
}

unsigned int HandWeapon::capacity() const
{
    return magazine_.capacity;
}

std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    if((unlimitedPatrons() || (patronsInMagazine() > 0) ) && !shotDelayIsActive_ && !reloadDelayIsActive_)
    {
        QTimer::singleShot(shotDelay_, [&](){ shotDelayIsActive_ = false; });
        shotDelayIsActive_ = true;
        if(magazine_.patrons > 0)
        {
            --magazine_.patrons;
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
    if(soundPlayer_.media().canonicalUrl() != QUrl(shotSound_))
    {
        soundPlayer_.setMedia(QUrl(shotSound_));
        soundPlayer_.play();
    }
    else
    {
        if(soundPlayer_.state() == QMediaPlayer::PlayingState)
        {
            soundPlayer_.setPosition(0);
        }
        else
        {
            soundPlayer_.play();
        }
    }
}

void HandWeapon::playReloadSound()
{
    soundPlayer_.setMedia(QUrl(HANDWEAPON_RELOAD_SOUND));
    soundPlayer_.play();
}

void HandWeapon::reload()
{
    if(!unlimitedPatrons())
    {
        QTimer::singleShot(reloadDelay_, [&](){ reloadDelayIsActive_ = false; });
        reloadDelayIsActive_ = true;
        if(loadMagazine())
        {
            playReloadSound();
        }
    }
}

bool HandWeapon::loadMagazine()
{
    if(patrons_ > 0 && magazine_.patrons < magazine_.capacity)
    {
        auto requiredPatrons = magazine_.capacity - magazine_.patrons;
        if(patrons_ >= requiredPatrons)
        {
            patrons_ -= requiredPatrons;
            magazine_.patrons += requiredPatrons;
        }
        else
        {
            magazine_.patrons += patrons_;
            patrons_ = 0;
        }
        return true;
    }
    return false;
}

void HandWeapon::addPatrons(unsigned int patrons)
{
    patrons_ += patrons;
}
