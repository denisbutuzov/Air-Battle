#pragma once

#include <QtGlobal>

#include <map>
#include <memory>

#include "AbstractSubject.h"

class HandWeapon;
class QGraphicsScene;
class Gunshell;

const int countPatronsInWeapon = 6;
const int countAddingPatrons = 2;

class Magazine
        : public AbstractSubject
{
public:
    enum class WEAPON
    {
        Gun,
        Machinegun,
        Bazooka
    };

public:
    Magazine(const std::shared_ptr<QGraphicsScene> &scene);

    void addWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    int patronsInWeapon() const;
    int patronInMagazine() const;
    int maxPatronsInWeapon() const;
    WEAPON currentWeapon() const;

private:
    using armament = std::tuple<std::unique_ptr<HandWeapon>, int, int>;
    using weaponsMap = std::map<WEAPON, armament>;

private:
    void addPatrons(WEAPON weaponType, std::unique_ptr<HandWeapon> &&weapon);

private:
    weaponsMap weapons_;
    weaponsMap::iterator currentWeapon_;
};
