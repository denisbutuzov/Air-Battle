#include <QGraphicsScene>
#include <QTextDocument>

#include "SpecialObjects/Subjects/Equipment.h"

#include "EquipmentObserver.h"

EquipmentObserver::EquipmentObserver(std::weak_ptr<Equipment> equipment)
    : subject_(equipment)
    , currentWeapontType_(Equipment::Weapon::Gun)
{
    text_.setDefaultTextColor(Qt::white);
    text_.setFont(QFont("times", 20, QFont::Bold));
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
    }
}

void EquipmentObserver::update()
{
    if(auto wp = subject_.lock())
    {
        if(currentWeapontType_ != wp->currentWeapon())
        {
            clearMagazine();
        }
        setText(wp->currentWeapon());
        if(static_cast<int>(patrons_.size()) < wp->patronsInWeapon())
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
        scene_.lock()->addItem(&text_);
        text_.setPos(coordinate_);
        setText(subject_.lock()->currentWeapon());

        auto tempVal = subject_.lock()->patronInMagazine();
        for (int i = 0; i != tempVal; ++i)
        {
            addPatron();
        }
    }
}

void EquipmentObserver::addPatron()
{
    static const std::map<Equipment::Weapon, QString> PATRON_TYPE
    {
        { Equipment::Weapon::Machinegun, "Machinegun_patron" },
        { Equipment::Weapon::Bazooka, "Bazooka_patron" }
    };

    QString patronString(":/images/images/");
    QString currentPatronType = PATRON_TYPE.find(subject_.lock()->currentWeapon())->second;
    patronString.push_back(currentPatronType + ".png");
    auto patron = std::make_unique<QGraphicsPixmapItem>(QPixmap(patronString));
    if(!patrons_.empty())
    {
        patron->setPos(patrons_.top()->pos() + QPointF(0.0, -(patron->pixmap().height() + 1.0)));
    }
    else
    {
        patron->setPos(coordinate_ + QPointF(0.0, text_.document()->size().height() + (subject_.lock()->maxPatronsInWeapon()-1)*(patron->pixmap().height() + 1.0)));
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
    while(static_cast<int>(patrons_.size()) != subject_.lock()->patronsInWeapon())
    {
        callBack();
    }
}

void EquipmentObserver::setText(Equipment::Weapon weapon)
{
    static const std::map<Equipment::Weapon, QString> WEAPON_TYPE
    {
        { Equipment::Weapon::Gun, "Gun" },
        { Equipment::Weapon::Machinegun, "Machinegun" },
        { Equipment::Weapon::Bazooka, "Bazooka" }
    };

    QString text = WEAPON_TYPE.find(weapon)->second;
    text.push_back(": ");
    if(weapon == Equipment::Weapon::Gun)
    {
        text.push_back("∞");
    }
    else
    {
        text.push_back(QString::number(subject_.lock()->patronInMagazine()) + "/" + QString::number(subject_.lock()->patronsInWeapon()));
    }
    text_.setPlainText(text);
}

void EquipmentObserver::clearMagazine()
{
    while(!patrons_.empty())
    {
        removePatron();
    }
}
