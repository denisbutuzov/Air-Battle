#include <QFont>

#include "Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    //initialize the score
    health_ = 3;

    //draw the text
    setPlainText(QString("Health: " + QString::number(health_)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 15));
}

void Health::decrease()
{
    health_--;
    //update score on view
    setPlainText(QString("Health: " + QString::number(health_)));
}
