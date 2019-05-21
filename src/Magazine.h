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

private:
    enum class WEAPON
    {
        Gun,
        Machinegun,
        Bazooka
    };

    using weaponsMap = std::map<WEAPON, std::unique_ptr<HandWeapon>>;

    weaponsMap weapons_;
    weaponsMap::iterator currentWeapon_;
};
