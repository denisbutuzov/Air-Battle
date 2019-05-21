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
        auto iter = weapons_.find(WEAPON::Machinegun);
        if (iter == weapons_.end())
        {
            weapons_.insert({WEAPON::Machinegun, std::make_pair(std::move(gun), 15)});
        }
        else
        {
            iter->second.second += 10;
        }
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        auto iter = weapons_.find(WEAPON::Bazooka);
        if (iter == weapons_.end())
        {
            weapons_.insert({WEAPON::Bazooka, std::make_pair(std::move(gun), 15)});
        }
        else
        {
            iter->second.second += 10;
        }
    }
}

void Magazine::changeWeapon()
{
    if(++currentWeapon_ == weapons_.end())
    {
        currentWeapon_ = weapons_.begin();
    }
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
        return currentWeapon_->second.first->shoot(x, y);
    }
    else
    {
        changeWeapon();
        return shoot(x, y);
    }
}
