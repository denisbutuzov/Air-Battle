#include "GameObjects/Gunshells/Gunshell.h"

#include "HandBazooka.h"

constexpr unsigned int BAZOOKA_CAPACITY = 5;
constexpr unsigned int BAZOOKA_PATRONS = 5;
constexpr unsigned int BAZOOKA_SHOT_DELAY = 500;
constexpr const char *BAZOOKA_SHOT_SOUND = "qrc:/sounds/sounds/boom.wav";
constexpr const char *BAZOOKA_GUNSHELL_IMAGE = ":/images/images/Bazooka_gunshell.png";

HandBazooka::HandBazooka(std::weak_ptr<QGraphicsScene> scene)
    : HandWeapon(scene, BAZOOKA_CAPACITY, BAZOOKA_PATRONS,
                 BAZOOKA_SHOT_DELAY, BAZOOKA_SHOT_SOUND)
{
}

std::unique_ptr<Gunshell> HandBazooka::createGunshell(qreal x, qreal y)
{    
    auto gunshell = std::make_unique<Gunshell>(scene(), 2);
    gunshell->setPixmap(QPixmap(BAZOOKA_GUNSHELL_IMAGE));
    gunshell->setPos(QPointF(x, y));
    return gunshell;
}
