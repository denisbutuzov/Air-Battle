#include "AbstractLevelFactory.h"

class Level1Factory
        : public AbstractLevelFactory
{
public:
    Level1Factory() = default;

    virtual std::unique_ptr<Enemy> enemy() const;
    virtual std::unique_ptr<Weapon> weapon() const;
};
