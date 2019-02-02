#include <QGraphicsScene>

#include "Level.h"

Level::Level()
    : level_(1)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    setPlainText(QString("LEVEL: " + QString::number(level_)));
}

void Level::show(QGraphicsScene *scene_, QPointF coordinate)
{
    scene_->addItem(this);
    setPos(coordinate);
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
