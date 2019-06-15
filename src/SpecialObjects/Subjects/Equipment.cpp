#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Equipment.h"

Equipment::Equipment(std::weak_ptr<QGraphicsScene> scene)
{
    weapons_.insert({Weapon::Gun, std::make_tuple(std::make_unique<HandGun>(scene), 0, 0)});
    currentWeapon_ = weapons_.begin();
}

void Equipment::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        addPatrons(Weapon::Machinegun, std::move(gun));
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        addPatrons(Weapon::Bazooka, std::move(gun));
    }
}

void Equipment::changeWeapon()
{
    if(++currentWeapon_ == weapons_.end())
    {
        currentWeapon_ = weapons_.begin();
    }
    notify();
}

void Equipment::reloadWeapon()
{
    auto &patronsInMagazine = std::get<1>(currentWeapon_->second);
    auto &patronsInWeapon = std::get<2>(currentWeapon_->second);
    if(patronsInMagazine != 0)
    {
        auto lackPatronsInWeapon = countPatronsInWeapon - patronsInWeapon;
        if(patronsInMagazine >= lackPatronsInWeapon)
        {
            patronsInWeapon += lackPatronsInWeapon;
            patronsInMagazine -= lackPatronsInWeapon;
        }
        else
        {
            patronsInWeapon += patronsInMagazine;
            patronsInMagazine = 0;
        }
        notify();
    }
}

std::unique_ptr<Gunshell> Equipment::shoot(qreal x, qreal y)
{
    auto weapon = currentWeapon_->first;
    auto &patronsInMagazine = std::get<1>(currentWeapon_->second);
    auto &patronsInWeapon = std::get<2>(currentWeapon_->second);
    if(weapon == Weapon::Gun)
    {
        return std::get<0>(currentWeapon_->second)->shoot(x,y);
    }
    else if(patronsInWeapon != 0)
    {
        patronsInWeapon--;
        notify();
        return std::get<0>(currentWeapon_->second)->shoot(x,y);
    }
    else if(patronsInMagazine != 0)
    {
        if(patronsInMagazine > countPatronsInWeapon)
        {
            patronsInMagazine -= countPatronsInWeapon;
            patronsInWeapon = countPatronsInWeapon;
        }
        else
        {
            patronsInWeapon = patronsInMagazine;
            patronsInMagazine = 0;
        }
        notify();
        return std::get<0>(currentWeapon_->second)->shoot(x,y);
    }
    else
    {
        weapons_.erase(currentWeapon_->first);
        changeWeapon();
        return shoot(x, y);
    }
}

int Equipment::patronsInWeapon() const
{
    return std::get<2>(currentWeapon_->second);
}

int Equipment::patronInMagazine() const
{
    return std::get<1>(currentWeapon_->second);
}

int Equipment::maxPatronsInWeapon() const
{
    return countPatronsInWeapon;
}

Equipment::Weapon Equipment::currentWeapon() const
{
    return currentWeapon_->first;
}

bool Equipment::isReadyToShot() const
{
    return std::get<0>(currentWeapon_->second)->isReadyToShoot();
}

void Equipment::addPatrons(Equipment::Weapon weaponType, std::unique_ptr<HandWeapon> &&weapon)
{
    auto iter = weapons_.find(weaponType);
    if (iter == weapons_.end())
    {
        weapons_.insert({weaponType, std::make_tuple(std::move(weapon), 0, countPatronsInWeapon)});
    }
    else
    {
        std::get<1>(iter->second) += countAddingPatrons;
        notify();
    }
}
