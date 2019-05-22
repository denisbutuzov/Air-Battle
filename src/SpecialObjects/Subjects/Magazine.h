#pragma once

#include <QtGlobal>

#include <map>
#include <memory>

class HandWeapon;
class QGraphicsScene;
class Gunshell;

class Magazine
{
public:
    Magazine(const std::shared_ptr<QGraphicsScene> &scene);
    void addWeapon(std::unique_ptr<HandWeapon> &&weapon);
    void changeWeapon();
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    unsigned int value() const;

private:
    enum class WEAPON
    {
        Gun,
        Machinegun,
        Bazooka
    };

    using armament = std::pair<std::unique_ptr<HandWeapon>, unsigned int>;
    using weaponsMap = std::map<WEAPON, armament>;

private:
    void addPatrons(WEAPON weaponType, std::unique_ptr<HandWeapon> &&weapon);

private:
    weaponsMap weapons_;
    weaponsMap::iterator currentWeapon_;
};
