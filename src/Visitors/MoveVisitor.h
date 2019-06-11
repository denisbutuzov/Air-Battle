#pragma once

#include "AbstractVisitor.h"

class MoveVisitor
        : public AbstractVisitor
{
public:
    MoveVisitor() = default;
    virtual ~MoveVisitor() override = default;
    virtual void visitEnemy(Enemy *enemy) override final;
    virtual void visitWeapon(Weapon *weapon) override final;
    virtual void visitGunshell(Gunshell *gunshell) override final;
};
