#include <QGraphicsScene>
#include <QTextDocument>

#include "SpecialObjects/Subjects/Equipment.h"
#include "HandWeapons/HandWeapon.h"
#include "AppSettings.h"

#include "EquipmentObserver.h"

/*!
 * \param equipment Слабый указатель на объект снаряжения игрока.
 *
 * Прикрепляет данный наблюдатель за объектом снаряжения игрока,
 * переданного в качестве аргумента.
 */
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

/*!
 * Обновляет представление в соответствии с текущим состоянием снаряжения игрока.
 */
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

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param coordinate Позиция для отображения наблюдателя.
 *
 * Отображает объект наблюдателя на игровой сцене в позиции переданной
 * в качестве аргумента.
 */
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

/*!
 * Добавляет изображение соответствующего патрона на представление наблюдателя.
 */
void EquipmentObserver::addPatron()
{
    static const std::map<Equipment::WeaponType, QString> PATRON_TYPE
    {
        { Equipment::WeaponType::Machinegun, AppSettings::instance().objects().machinegun_.patron_},
        { Equipment::WeaponType::Bazooka, AppSettings::instance().objects().bazooka_.patron_}
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

/*!
 * Удаляет изображение патрона из представления наблюдателя.
 */
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

/*!
 * \param weapon Название вида оружия.
 *
 * Устанавливает название вида оружия для отображения наблюдателем.
 */
void EquipmentObserver::setText(Equipment::WeaponType weapon)
{
    static const std::map<Equipment::WeaponType, QString> WEAPON_TYPE
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

/*!
 * Удаляет отображения всех патронов с представления наблюдателя.
 */
void EquipmentObserver::clearMagazine()
{
    while(!patrons_.empty())
    {
        removePatron();
    }
}
