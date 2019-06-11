#pragma once

class Enemy;
class Gunshell;
class Weapon;

class AbstractVisitor
{
public:
    virtual ~AbstractVisitor() = default;
    virtual void visitEnemy(Enemy *enemy) = 0;
    virtual void visitWeapon(Weapon *weapon) = 0;
    virtual void visitGunshell(Gunshell *gunshell) = 0;
protected:
    AbstractVisitor() = default;
};
