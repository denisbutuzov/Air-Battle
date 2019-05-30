#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Magazine.h"

Magazine::Magazine(const std::shared_ptr<QGraphicsScene> &scene)
{
    weapons_.insert({WEAPON::Gun, std::make_pair(std::make_unique<HandGun>(scene), 0)});
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
    auto gunshellNumber = currentWeapon_->second.second;
    if(weapon == WEAPON::Gun)
    {
        return currentWeapon_->second.first->shoot(x, y);
    }
    else if(gunshellNumber != 0)
    {
        currentWeapon_->second.second--;
        notify();
        return currentWeapon_->second.first->shoot(x, y);
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
    return currentWeapon_->second.second;
}

void Magazine::addPatrons(Magazine::WEAPON weaponType, std::unique_ptr<HandWeapon> &&weapon)
{
    auto iter = weapons_.find(weaponType);
    if (iter == weapons_.end())
    {
        weapons_.insert({weaponType, std::make_pair(std::move(weapon), 15)});
    }
    else
    {
        iter->second.second += 10;
        notify();
    }
}
