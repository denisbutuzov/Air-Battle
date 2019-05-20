#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Magazine.h"

#include <QDebug>

Magazine::Magazine(const std::shared_ptr<QGraphicsScene> &scene)
{
    weapons_.insert({WEAPON::Gun, std::make_unique<HandGun>(scene)});
}

void Magazine::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        if (weapons_.find(WEAPON::Machinegun) != weapons_.end())
        {
            qDebug() << "Такое оружие уже есть";
        }
        else
        {
            weapons_.insert({WEAPON::Machinegun, std::move(weapon)});
            qDebug() << "Такого оружия НЕТ. Добавляем";
        }
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        if (weapons_.find(WEAPON::Bazooka) != weapons_.end())
        {
            qDebug() << "Такое оружие уже есть";
        }
        else
        {
            qDebug() << "Такого оружия НЕТ. Добавляем";
            weapons_.insert({WEAPON::Bazooka, std::move(weapon)});
        }
    }
}

std::unique_ptr<Gunshell> Magazine::shoot(qreal x, qreal y)
{
    return weapons_.find(WEAPON::Gun)->second->shoot(x, y);
}
