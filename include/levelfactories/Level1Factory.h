#include "AbstractLevelFactory.h"

class Level1Factory
        : public AbstractLevelFactory
{
public:
    Level1Factory(QGraphicsScene *scene);
    virtual ~Level1Factory() override = default;

    virtual Enemy *enemy() const override final;
    virtual Weapon *weapon() const override final;
};
