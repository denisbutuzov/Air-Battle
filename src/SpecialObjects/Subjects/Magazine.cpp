#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Magazine.h"

Magazine::Magazine(const std::shared_ptr<QGraphicsScene> &scene)
{
    weapons_.insert({WEAPON::Gun, std::make_tuple(std::make_unique<HandGun>(scene), 0, 0)});
    currentWeapon_ = weapons_.begin();
}

void Magazine::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        addPatrons(WEAPON::Machinegun, std::move(gun));
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        addPatrons(WEAPON::Bazooka, std::move(gun));
    }
}

void Magazine::changeWeapon()
{
    if(++currentWeapon_ == weapons_.end())
    {
        currentWeapon_ = weapons_.begin();
    }
    notify();
}

std::unique_ptr<Gunshell> Magazine::shoot(qreal x, qreal y)
{
    auto weapon = currentWeapon_->first;
    auto &patronsInMagazine = std::get<1>(currentWeapon_->second);
    auto &patronsInWeapon = std::get<2>(currentWeapon_->second);
    if(weapon == WEAPON::Gun)
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
        if(patronsInMagazine > 15)
        {
            patronsInMagazine -= 15;
            patronsInWeapon = 15;
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

int Magazine::value() const
{
    return std::get<2>(currentWeapon_->second);
}

void Magazine::addPatrons(Magazine::WEAPON weaponType, std::unique_ptr<HandWeapon> &&weapon)
{
    auto iter = weapons_.find(weaponType);
    if (iter == weapons_.end())
    {
        weapons_.insert({weaponType, std::make_tuple(std::move(weapon), 0, 15)});
    }
    else
    {
        std::get<1>(iter->second) += 10;
        notify();
    }
}
