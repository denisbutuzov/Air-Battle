﻿#pragma once

#include <QtGlobal>

#include <map>
#include <memory>

#include "AbstractSubject.h"

class HandWeapon;
class QGraphicsScene;
class Gunshell;

constexpr int countPatronsInWeapon = 6;
constexpr int countAddingPatrons = 2;

class Equipment
        : public AbstractSubject
{
public:
    enum class Weapon
    {
        Gun,
        Machinegun,
        Bazooka
    };
public:
    Equipment(std::weak_ptr<QGraphicsScene> scene);
    void addWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    void reloadWeapon();
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    int patronsInWeapon() const;
    int patronInMagazine() const;
    int maxPatronsInWeapon() const;
    Weapon currentWeapon() const;
    bool isReadyToShoot() const;
private:
    using armament = std::tuple<std::unique_ptr<HandWeapon>, int, int>;
    using weaponsMap = std::map<Weapon, armament>;
private:
    void addPatrons(Weapon weaponType, std::unique_ptr<HandWeapon> &&weapon);
private:
    weaponsMap weapons_;
    weaponsMap::iterator currentWeapon_;
};
