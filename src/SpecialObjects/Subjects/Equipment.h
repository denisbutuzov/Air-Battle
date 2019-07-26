#pragma once

#include <QtGlobal>

#include <map>
#include <memory>

#include "AbstractSubject.h"

class HandWeapon;
class Gunshell;
class QGraphicsScene;

/*!
 * \ingroup Subjects
 * \brief Класс снаряжения игрока.
 *
 * Реализует класс снаряжения.
 */
class Equipment
        : public AbstractSubject
{
    /*!
     * Для разрешения вызова закрытого метода `std::unique_ptr<Gunshell>
     * shoot(qreal x, qreal y)` объектом игрока, вызов которого в остальных случаях
     * нежелателен.
     */
    friend class PlayerObject;

public:
    /*!
     * \brief Тип оружия.
     *
     * Используется для идентификации типа ручного оружия.
     */
    enum class WeaponType
    {
        Gun, ///<Пистолет
        Machinegun, ///<Пулемет
        Bazooka ///<Базука
    };
    ///Псевдоним пары <Тип оружия, ручное оружие>
    using WeaponsMap = std::map<WeaponType, std::unique_ptr<HandWeapon>>;
public:
    ///Конструктор с одним аргументом.
    Equipment(std::weak_ptr<QGraphicsScene> scene);
    ///Метод для добавления ручного оружия в снаряжение.
    void addWeapon(std::unique_ptr<HandWeapon> &&weapon);
    ///Метод удаления ручного оружия из снаряжения.
    void removeWeapon(WeaponType weaponType);
    ///Метод смены текущего ручного оружия.
    void changeWeapon();
    ///Метод перезарядки текущего ручного оружия.
    void reloadWeapon();
    ///Метод, возвращающий текущее ручное оружие.
    WeaponsMap::value_type &currentWeapon() const;
private:
    ///Метод, реализующий выстрел из ручного оружия.
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    ///Метод для добавления ручного оружия в снаряжение или патронов в обойму оружия.
    void addWeaponOrPatrons(WeaponType weaponType, std::unique_ptr<HandWeapon> &&weapon);
private:
    WeaponsMap weapons_;
    WeaponsMap::iterator currentWeapon_;
};
