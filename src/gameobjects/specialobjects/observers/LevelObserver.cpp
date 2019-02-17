#include <QGraphicsScene>

#include "Level.h"

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
    setPlainText(QString("Level: " + QString::number(subject_->level())));
}

void LevelObserver::show(QGraphicsScene *scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
    update();
}
