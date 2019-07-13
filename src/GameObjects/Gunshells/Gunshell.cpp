#include <QGraphicsScene>
#include <QTimer>

#include "Visitors/AbstractVisitor.h"

#include "Gunshell.h"

constexpr const char *GUNSHELL_BOOM_IMAGE = ":/images/images/Gunshell_boom.png";

Gunshell::Gunshell(std::weak_ptr<QGraphicsScene> scene,
                   int damage,
                   std::shared_ptr<MoveStrategy> moveStrategy)
    : MovableObject(scene, moveStrategy)
    , damage_(damage)
{
}

Gunshell::~Gunshell()
{
    if(auto wp = scene().lock())
    {
        if(y() > 0)
        {
            QGraphicsPixmapItem *pixmap = new QGraphicsPixmapItem(QPixmap(GUNSHELL_BOOM_IMAGE));
            pixmap->setPos(pos());
            wp->addItem(pixmap);
            QTimer::singleShot(std::chrono::milliseconds(100), [pixmap = pixmap](){ delete pixmap; });
        }
    }
}

void Gunshell::accept(AbstractVisitor &visitor)
{
    visitor.visitGunshell(this);
}

void Gunshell::setDamage(int damage)
{
    damage_ = damage;
}

int Gunshell::damage() const
{
    return damage_;
}
