#include <QGraphicsScene>
#include <QTextDocument>

#include "SpecialObjects/Subjects/Equipment.h"
#include "HandWeapons/HandWeapon.h"

#include "EquipmentObserver.h"

constexpr const char *MACHINEGUN_PATRON_IMAGE = ":/images/images/Machinegun_patron.png";
constexpr const char *BAZOOKA_PATRON_IMAGE = ":/images/images/Bazooka_patron.png";

EquipmentObserver::EquipmentObserver(std::weak_ptr<Equipment> equipment)
    : subject_(equipment)
{
    weaponType_.setDefaultTextColor(Qt::white);
    weaponType_.setFont(QFont("times", 20, QFont::Bold));
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
        currentWeaponType_ = wp->currentWeapon().first;
    }
}

void EquipmentObserver::update()
{
    if(auto wp = subject_.lock())
    {
        auto &weapon = wp->currentWeapon();
        if(currentWeaponType_ != weapon.first)
        {
            clearMagazine();
            currentWeaponType_ = weapon.first;
        }
        setText(weapon.first);
        if(static_cast<unsigned int>(patrons_.size()) < weapon.second->patronsInMagazine())
        {
            repeatWhileSizesAreNotEqual(std::bind(&EquipmentObserver::addPatron, this));
        }
        else
        {
            repeatWhileSizesAreNotEqual(std::bind(&EquipmentObserver::removePatron, this));
        }
    }
}

void EquipmentObserver::show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    if(!scene_.expired() && !subject_.expired())
    {
        scene_.lock()->addItem(&weaponType_);
        weaponType_.setPos(coordinate_);
        setText(subject_.lock()->currentWeapon().first);

        auto tempVal = subject_.lock()->currentWeapon().second->patronsInMagazine();
        for (unsigned int i = 0; i != tempVal; ++i)
        {
            addPatron();
        }
    }
}

void EquipmentObserver::addPatron()
{
    static const std::map<Equipment::WeaponType, const char *> PATRON_TYPE
    {
        { Equipment::WeaponType::Machinegun, MACHINEGUN_PATRON_IMAGE },
        { Equipment::WeaponType::Bazooka, BAZOOKA_PATRON_IMAGE }
    };

    auto currentPatronType = PATRON_TYPE.find(subject_.lock()->currentWeapon().first)->second;
    auto patron = std::make_unique<QGraphicsPixmapItem>(QPixmap(currentPatronType));
    if(!patrons_.empty())
    {
        patron->setPos(patrons_.top()->pos() + QPointF(0.0, -(patron->pixmap().height() + 1.0)));
    }
    else
    {
        patron->setPos(coordinate_ + QPointF(0.0, weaponType_.document()->size().height() +
                                                  (subject_.lock()->currentWeapon().second->capacity() - 1) *
                                                  (patron->pixmap().height() + 1.0)));
    }
    scene_.lock()->addItem(patron.get());
    patrons_.push(std::move(patron));
}

void EquipmentObserver::removePatron()
{
    patrons_.pop();
}

void EquipmentObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack)
{
    unsigned int patronsInMagazine = subject_.lock()->currentWeapon().second->patronsInMagazine();
    while(static_cast<unsigned int>(patrons_.size()) != patronsInMagazine)
    {
        callBack();
    }
}

void EquipmentObserver::setText(Equipment::WeaponType weapon)
{
    static const std::map<Equipment::WeaponType, const char *> WEAPON_TYPE
    {
        { Equipment::WeaponType::Gun, "Gun" },
        { Equipment::WeaponType::Machinegun, "Machinegun" },
        { Equipment::WeaponType::Bazooka, "Bazooka" }
    };

    QString text = WEAPON_TYPE.find(weapon)->second;
    text.push_back(": ");
    if(weapon == Equipment::WeaponType::Gun)
    {
        text.push_back("∞");
    }
    else
    {
        text.push_back(QString::number(subject_.lock()->currentWeapon().second->patronsInStorage()) +
                       "/" + QString::number(subject_.lock()->currentWeapon().second->patronsInMagazine()));
    }
    weaponType_.setPlainText(text);
}

void EquipmentObserver::clearMagazine()
{
    while(!patrons_.empty())
    {
        removePatron();
    }
}
