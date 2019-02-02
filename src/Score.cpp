#include <QGraphicsScene>
#include <QFont>

#include "Score.h"

Score *Score::instance_ = nullptr;

Score::Score()
    : score_(0)
{
    //draw the text
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    setPlainText(QString("Score: " + QString::number(score_)));
}

Score *Score::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Score();
    }
    return instance_;
}

void Score::show(QGraphicsScene *scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
}

void Score::increase()
{
    //update score on view
    setPlainText(QString("Score: " + QString::number(++score_)));
}
