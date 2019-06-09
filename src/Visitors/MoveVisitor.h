#pragma once

#include "AbstractVisitor.h"

class MoveVisitor
        : public AbstractVisitor
{
public:
    MoveVisitor() = default;
    virtual ~MoveVisitor() override = default;
    virtual void visitEnemy(Enemy *enemy) override final;
};
