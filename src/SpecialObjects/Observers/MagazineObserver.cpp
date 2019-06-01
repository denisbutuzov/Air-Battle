#include <QGraphicsScene>

#include "SpecialObjects/Subjects/Magazine.h"

#include <QTextDocument>

#include "MagazineObserver.h"

MagazineObserver::MagazineObserver(Magazine *health)
    : subject_(health)
{
    subject_->attach(this);
    text_.setDefaultTextColor(Qt::white);
    text_.setFont(QFont("times", 20, QFont::Bold));
}

void MagazineObserver::update()
{
    setText(subject_->currentWeapon());
    if(static_cast<int>(patrons_.size()) < subject_->patronsInWeapon())
    {
        repeatWhileSizesAreNotEqual(std::bind(&MagazineObserver::addPatron, this));
    }
    else
    {
        repeatWhileSizesAreNotEqual(std::bind(&MagazineObserver::removePatron, this));
    }
}

void MagazineObserver::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    (scene_ = scene)->addItem(&text_);
    text_.setPos(coordinate_ = coordinate);
    setText(subject_->currentWeapon());
    for (int i = 0; i != subject_->patronsInWeapon(); ++i)
    {
        addPatron();
    }
}

void MagazineObserver::addPatron()
{
    auto *patron = new QGraphicsPixmapItem(QPixmap(":/images/images/Heart.png").scaled(20, 20));
    if(!patrons_.empty())
    {
        patron->setPos(patrons_.top()->pos() + QPointF(0.0, -(patron->pixmap().height() + 1.0)));
    }
    else
    {
        patron->setPos(coordinate_ + QPointF(0.0, text_.document()->size().height() + 14*(patron->pixmap().height() + 1.0)));
    }
    scene_->addItem(patron);
    patrons_.push(patron);
}

void MagazineObserver::removePatron()
{
    auto *patron = patrons_.top();
    patrons_.pop();
    delete patron;
}

void MagazineObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack)
{
    while(static_cast<int>(patrons_.size()) != subject_->patronsInWeapon())
    {
        callBack();
    }
}

void MagazineObserver::setText(Magazine::WEAPON weapon)
{
    static const std::map<Magazine::WEAPON, QString> WEAPON_TYPE
    {
        { Magazine::WEAPON::Gun, "Gun" },
        { Magazine::WEAPON::Machinegun, "Machinegun" },
        { Magazine::WEAPON::Bazooka, "Bazooka" }
    };

    QString text = WEAPON_TYPE.find(weapon)->second;
    text.push_back(": ");
    if(weapon == Magazine::WEAPON::Gun)
    {
        text.push_back("∞");
    }
    else
    {
        text.push_back(QString::number(subject_->patronInMagazine()) + "/" + QString::number(subject_->patronsInWeapon()));
    }
    text_.setPlainText(text);
}
