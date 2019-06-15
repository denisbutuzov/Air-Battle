#include "GameObjects/Gunshells/Gunshell.h"

#include "HandMachinegun.h"

constexpr int MACHINEGUN_CAPACITY = 12;
constexpr int MACHINEGUN_BEGING_PATRONS = 24;
constexpr int MACHINEGUN_SHOT_DELAY = 50;
constexpr const char *MACHINEGUN_SHOT_SOUND = "qrc:/sounds/sounds/bullet.wav";
constexpr const char *MACHINEGUN_GUNSHELL_IMAGE = ":/images/images/Machinegun_gunshell.png";

HandMachinegun::HandMachinegun(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, MACHINEGUN_CAPACITY, MACHINEGUN_BEGING_PATRONS,
                 MACHINEGUN_SHOT_DELAY, MACHINEGUN_SHOT_SOUND)
{
}

std::unique_ptr<Gunshell> HandMachinegun::createGunshell(qreal x, qreal y)
{
    static enum class SIDE {LEFT, RIGHT} side;

    std::unique_ptr<Gunshell> gunshell;
    if(side == SIDE::LEFT)
    {
        side = SIDE::RIGHT;
        gunshell = std::make_unique<Gunshell>(scene(), 1);
        gunshell->setPos(QPointF(x - 30.0, y + 60.0));
    }
    else if(side == SIDE::RIGHT)
    {
        side = SIDE::LEFT;
        gunshell = std::make_unique<Gunshell>(scene(), 1);
        gunshell->setPos(QPointF(x + 30.0, y + 60.0));
    }
    gunshell->setPixmap(QPixmap(MACHINEGUN_GUNSHELL_IMAGE));
    return gunshell;
}
