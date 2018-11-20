#include <QFont>

#include "Score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score
    score_ = 0;

    //draw the text
    setPlainText(QString("Score: " + QString::number(score_)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 15));
}

void Score::increase()
{
    score_++;
    //update score on view
    setPlainText(QString("Score: " + QString::number(score_)));
}
