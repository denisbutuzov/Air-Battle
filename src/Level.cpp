#include <QGraphicsScene>

#include "Level.h"

Level::Level(QGraphicsScene *scene, QPointF coordinate)
    : level_(1)
    , scene_(scene)
    , coordinate_(coordinate)
{
}

void Level::init()
{
    scene_->addItem(this);
    setPos(coordinate_);
    setPlainText(QString("LEVEL: " + QString::number(level_)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
}

unsigned int Level::level() const
{
    return level_;
}

void Level::change()
{
    if(level_ != 3)
    {
        setPlainText(QString("LEVEL: " + QString::number(++level_)));
    }
}
