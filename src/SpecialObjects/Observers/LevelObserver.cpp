#include <QGraphicsScene>

#include "SpecialObjects/Subjects/Level.h"

#include "LevelObserver.h"

LevelObserver::LevelObserver(Level *level)
    : subject_(level)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    subject_->attach(this);
}

void LevelObserver::update()
{
    setPlainText(QString("Level: " + QString::number(subject_->value())));
}

void LevelObserver::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
    update();
}
