#include "GameObjects/Enemies/Enemy.h"

#include "MoveVisitor.h"

void MoveVisitor::visitEnemy(Enemy *enemy)
{
    enemy->move();
}
