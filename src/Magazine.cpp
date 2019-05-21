#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Magazine.h"

Magazine::Magazine(const std::shared_ptr<QGraphicsScene> &scene)
{
    weapons_.insert({WEAPON::Gun, std::make_unique<HandGun>(scene)});
    currentWeapon_ = weapons_.begin();
}

void Magazine::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        if (weapons_.find(WEAPON::Machinegun) == weapons_.end())
        {
            weapons_.insert({WEAPON::Machinegun, std::move(gun)});
        }
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        if (weapons_.find(WEAPON::Bazooka) == weapons_.end())
        {
            weapons_.insert({WEAPON::Bazooka, std::move(gun)});
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
    return currentWeapon_->second->shoot(x, y);
}
