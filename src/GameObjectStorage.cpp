#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjects/Bonuses/Bonus.h"
#include "Visitors/AbstractVisitor.h"
#include "additionals.h"

#include "GameObjectStorage.h"

/*!
 * \param object Указатель с правами исключительного владения на
 * способный к движению объект.
 *
 * Добавляет в хранилище объект, переданный в качестве аргумента.
 */
void GameObjectStorage::pushMovableObject(std::unique_ptr<MovableObject> &&object)
{
    if(auto enemy = dynamic_unique_cast<Enemy>(std::move(object)))
    {
        enemies_.push_back(std::move(enemy));
    }
    else if(auto weapon = dynamic_unique_cast<Weapon>(std::move(object)))
    {
        weapons_.push_back(std::move(weapon));
    }
    else if(auto gunshell = dynamic_unique_cast<Gunshell>(std::move(object)))
    {
        gunshells_.push_back(std::move(gunshell));
    }
    else if(auto bonus = dynamic_unique_cast<Bonus>(std::move(object)))
    {
        bonuses_.push_back(std::move(bonus));
    }
}

/*!
 * \param enemy Указатель с правами исключительного владения на объект врага.
 *
 * Добавляет в хранилище объект врага, переданный в качестве аргумента.
 */
void GameObjectStorage::pushEnemy(std::unique_ptr<Enemy> &&enemy)
{
    enemies_.push_back(std::move(enemy));
}

/*!
 * \param weapon Указатель с правами исключительного владения на объект оружия.
 *
 * Добавляет в хранилище объект оружия, переданный в качестве аргумента.
 */
void GameObjectStorage::pushWeapon(std::unique_ptr<Weapon> &&weapon)
{
    weapons_.push_back(std::move(weapon));
}

/*!
 * \param gunshell Указатель с правами исключительного владения на объект оружейного снаряда.
 *
 * Добавляет в хранилище объект оружейного снаряда, переданный в качестве аргумента.
 */
void GameObjectStorage::pushGunshell(std::unique_ptr<Gunshell> &&gunshell)
{
    gunshells_.push_back(std::move(gunshell));
}

/*!
 * \param bonus Указатель с правами исключительного владения на объект бонуса.
 *
 * Добавляет в хранилище объект бонуса, переданный в качестве аргумента.
 */
void GameObjectStorage::pushBonus(std::unique_ptr<Bonus> &&bonus)
{
    bonuses_.push_back(std::move(bonus));
}

/*!
 * \param visitor Объект посетителя.
 *
 * Применяет объект посетителя ко всех объектам, хранящимся в хранилище.
 */
void GameObjectStorage::accept(AbstractVisitor &visitor)
{
    acceptToEnemies(visitor);
    acceptToWeapons(visitor);
    acceptToGunshells(visitor);
    acceptToBonuses(visitor);
}

/*!
 * \param visitor Объект посетителя.
 *
 * Применяет объект посетителя ко всех объектам врагов, хранящимся в хранилище.
 */
void GameObjectStorage::acceptToEnemies(AbstractVisitor &visitor)
{
    std::for_each(std::begin(enemies_), std::end(enemies_), [&visitor](auto &obj){ obj->accept(visitor); });
}

/*!
 * \param visitor Объект посетителя.
 *
 * Применяет объект посетителя ко всех объектам оружия, хранящимся в хранилище.
 */
void GameObjectStorage::acceptToWeapons(AbstractVisitor &visitor)
{
    std::for_each(std::begin(weapons_), std::end(weapons_), [&visitor](auto &obj){ obj->accept(visitor); });
}

/*!
 * \param visitor Объект посетителя.
 *
 * Применяет объект посетителя ко всех объектам оружейных снарядов, хранящимся в хранилище.
 */
void GameObjectStorage::acceptToGunshells(AbstractVisitor &visitor)
{
    std::for_each(std::begin(gunshells_), std::end(gunshells_), [&visitor](auto &obj){ obj->accept(visitor); });
}

/*!
 * \param visitor Объект посетителя.
 *
 * Применяет объект посетителя ко всех объектам бонусов, хранящимся в хранилище.
 */
void GameObjectStorage::acceptToBonuses(AbstractVisitor &visitor)
{
    std::for_each(std::begin(bonuses_), std::end(bonuses_), [&visitor](auto &obj){ obj->accept(visitor); });
}

/*!
 * \return Список указателей с правами исключительного владения на объекты врагов.
 */
std::list<std::unique_ptr<Enemy>> &GameObjectStorage::enemies()
{
    return enemies_;
}

/*!
 * \return Список указателей с правами исключительного владения на объекты оружия.
 */
std::list<std::unique_ptr<Weapon> > &GameObjectStorage::weapons()
{
    return weapons_;
}

/*!
 * \return Список указателей с правами исключительного владения на объекты оружейных снарядов.
 */
std::list<std::unique_ptr<Gunshell> > &GameObjectStorage::gunshells()
{
    return gunshells_;
}

/*!
 * \return Список указателей с правами исключительного владения на объекты бонусов.
 */
std::list<std::unique_ptr<Bonus> > &GameObjectStorage::bonuses()
{
    return bonuses_;
}
