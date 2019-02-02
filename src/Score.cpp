#include <QGraphicsScene>
#include <QFont>

#include "Score.h"

Score *Score::instance_ = nullptr;

Score::Score()
    : score_(0)
{
    //draw the text
    setFont(QFont("times", 20, QFont::Bold));
    setDefaultTextColor(Qt::white);
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

void Score::show(QGraphicsScene *scene)
{
    scene->addItem(this);
}

void Score::increase()
{
    //update score on view
    setPlainText(QString("Score: " + QString::number(++score_)));
}
