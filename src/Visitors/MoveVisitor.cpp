#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Weapons/Weapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "GameObjects/Bonuses/Bonus.h"

#include "MoveVisitor.h"

void MoveVisitor::visitEnemy(Enemy *enemy)
{
    enemy->move();
}

void MoveVisitor::visitWeapon(Weapon *weapon)
{
    weapon->move();
}

void MoveVisitor::visitGunshell(Gunshell *gunshell)
{
    gunshell->move();
}

void MoveVisitor::visitBonus(Bonus *bonus)
{
    bonus->move();
}
