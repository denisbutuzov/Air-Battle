#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Equipment.h"

constexpr int COUNT_ADDING_PATRONS = 10;

Equipment::Equipment(std::weak_ptr<QGraphicsScene> scene)
{
    weapons_.insert({WeaponType::Gun, std::make_unique<HandGun>(scene)});
    currentWeapon_ = weapons_.begin();
}

void Equipment::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        addWeaponAndPatrons(WeaponType::Machinegun, std::move(gun));
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        addWeaponAndPatrons(WeaponType::Bazooka, std::move(gun));
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
    currentWeapon_->second->reload();
}

std::unique_ptr<Gunshell> Equipment::shoot(qreal x, qreal y)
{
    auto gunshell = currentWeapon_->second->shoot(x, y);
    notify();
    return gunshell;
}

Equipment::WeaponsMap::value_type &Equipment::currentWeapon() const
{
    return *currentWeapon_;
}

void Equipment::addWeaponAndPatrons(Equipment::WeaponType weaponType, std::unique_ptr<HandWeapon> &&weapon)
{
    auto iter = weapons_.find(weaponType);
    if (iter == weapons_.end())
    {
        weapons_.insert({weaponType, std::move(weapon)});
    }
    else
    {
        currentWeapon_->second->addPatrons(COUNT_ADDING_PATRONS);
        notify();
    }
}
