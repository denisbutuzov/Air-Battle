#pragma once

#include <QtGlobal>

#include <map>
#include <memory>

#include "AbstractSubject.h"

class HandWeapon;
class Gunshell;
class QGraphicsScene;

class Equipment
        : public AbstractSubject
{
    friend class PlayerObject;

public:
    enum class WeaponType
    {
        Gun,
        Machinegun,
        Bazooka
    };
    using WeaponsMap = std::map<WeaponType, std::unique_ptr<HandWeapon>>;
public:
    Equipment(std::weak_ptr<QGraphicsScene> scene);
    void addWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    void reloadWeapon();
    WeaponsMap::value_type &currentWeapon() const;
private:
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    void addWeaponAndPatrons(WeaponType weaponType, std::unique_ptr<HandWeapon> &&weapon);
private:
    WeaponsMap weapons_;
    WeaponsMap::iterator currentWeapon_;
};
