#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjects/Bonuses/Bonus.h"

#include "MoveVisitor.h"

/*!
 * \param enemy Объект врага для перемещения.
 *
 * Перемещает переданный объект врага.
 */
void MoveVisitor::visitEnemy(Enemy *enemy)
{
    enemy->move();
}

/*!
 * \param weapon Объект оружия для перемещения.
 *
 * Перемещает переданный объект оружия.
 */
void MoveVisitor::visitWeapon(Weapon *weapon)
{
    weapon->move();
}

/*!
 * \param gunshell Объект оружейного снаряда для перемещения.
 *
 * Перемещает переданный объект оружейного снаряда.
 */
void MoveVisitor::visitGunshell(Gunshell *gunshell)
{
    gunshell->move();
}

/*!
 * \param bonus Объект бонуса для перемещения.
 *
 * Перемещает переданный объект бонуса.
 */
void MoveVisitor::visitBonus(Bonus *bonus)
{
    bonus->move();
}
