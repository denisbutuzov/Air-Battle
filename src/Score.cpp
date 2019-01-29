#include <QGraphicsScene>
#include <QFont>

#include "Score.h"

Score *Score::instance_ = nullptr;

Score::Score()
{
    //initialize the score
    score_ = 0;

    //draw the text
    setPlainText(QString("Score: " + QString::number(score_)));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
}

void Score::init(QGraphicsScene *scene)
{
    scene->addItem(this);
}

Score *Score::instance()
{
    if(instance_ == nullptr)
    {
        instance_ = new Score();
    }
    return instance_;
}

void Score::increase()
{
    score_++;
    //update score on view
    setPlainText(QString("Score: " + QString::number(score_)));
}
