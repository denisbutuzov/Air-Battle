#include "Enemy.h"
#include "Gunshell.h"
#include "Weapon.h"

#include "MoveVisitor.h"

void MoveVisitor::visitEnemy(Enemy *enemy)
{
    enemy->move();
}

void MoveVisitor::visitGunshell(Gunshell *gunshell)
{
    gunshell->move();
}

void MoveVisitor::visitWeapon(Weapon *weapon)
{
    weapon->move();
}
