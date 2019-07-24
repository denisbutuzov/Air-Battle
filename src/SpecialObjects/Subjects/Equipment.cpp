#include "HandWeapons/HandGun.h"
#include "HandWeapons/HandMachinegun.h"
#include "HandWeapons/HandBazooka.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "additionals.h"

#include "Equipment.h"

constexpr unsigned int COUNT_ADDING_PATRONS = 10;

/*!
 * \param scene Слабый указатель на объект сцены.
 */
Equipment::Equipment(std::weak_ptr<QGraphicsScene> scene)
{
    weapons_.emplace(WeaponType::Gun, std::make_unique<HandGun>(scene));
    currentWeapon_ = weapons_.begin();
}

/*!
 * \param weapon Ручное оружие.
 *
 * Добавляет переданное ручное оружие в снаряжение.
 */
void Equipment::addWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    if(auto gun = dynamic_unique_cast<HandMachinegun>(std::move(weapon)))
    {
        addWeaponOrPatrons(WeaponType::Machinegun, std::move(gun));
    }
    else if(auto gun = dynamic_unique_cast<HandBazooka>(std::move(weapon)))
    {
        addWeaponOrPatrons(WeaponType::Bazooka, std::move(gun));
    }
}

/*!
 * \param weapon Тип оружия для удаления.
 *
 * Реализует удаление оружия из снаряжения и заменяет его следующий
 * из снаряжения. Оповещение всех наблюдателей.
 */
void Equipment::removeWeapon(WeaponType weapon)
{
    weapons_.erase(weapon);
    changeWeapon();
    notify();
}

/*!
 * Реализует смену текущего ручного оружия на следующее и
 * оповещение всех наблюдателей.
 */
void Equipment::changeWeapon()
{
    if(++currentWeapon_ == weapons_.end())
    {
        currentWeapon_ = weapons_.begin();
    }
    notify();
}

/*!
 * Реализует перезарядку текущего ручного оружия и оповещение
 * всех наблюдателей.
 */
void Equipment::reloadWeapon()
{
    currentWeapon_->second->reload();
    notify();
}

/*!
 * \param x Координата по оси Х на игровой сцене для порождения
 * оружейного снаряда.
 * \param y Координата по оси Y на игровой сцене для порождения
 * оружейного снаряда.
 *
 * \return Порожденный оружейный снаряд текущим оружием.
 *
 * Реализует выстрел из текущего оружия с порождением оружейного снаряда путем
 * делегирования обязанностей стрельбы текущему ручному оружию. Оповещает всех
 * наблюдателей.
 *
 * \note В случае если у текущего ручного оружия заканчиваются патроны в обойме,
 * производится перезарядка. Если патронов для текущего ручного оружия больше
 * не осталось, оружие заменяется следующим.
 */
std::unique_ptr<Gunshell> Equipment::shoot(qreal x, qreal y)
{
    auto &handWeapon = currentWeapon_->second;
    auto gunshell = handWeapon->shoot(x, y);
    if(!handWeapon->unlimitedPatrons())
    {
        if((handWeapon->patronsInMagazine() == 0) && (handWeapon->patronsInStorage() > 0))
        {
            reloadWeapon();
        }
        else if((handWeapon->patronsInMagazine() == 0) && (handWeapon->patronsInStorage() == 0))
        {
            removeWeapon(currentWeapon_->first);
        }
    }
    notify();
    return gunshell;
}


/*!
 * \return Текущее ручное оружие.
 */
Equipment::WeaponsMap::value_type &Equipment::currentWeapon() const
{
    return *currentWeapon_;
}

/*!
 * \param weaponType Тип ручного оружия.
 * \param weapon Ручное оружие.
 *
 * Реализует добавление ручного оружия в снаряжение или патронов в обойму оружия, если
 * такое оружие уже есть в снаряжении.
 */
void Equipment::addWeaponOrPatrons(WeaponType weaponType, std::unique_ptr<HandWeapon> &&weapon)
{
    auto iter = weapons_.find(weaponType);
    if (iter == weapons_.end())
    {
        weapons_.emplace(weaponType, std::move(weapon));
    }
    else
    {
        iter->second->addPatrons(COUNT_ADDING_PATRONS);
        notify();
    }
}
