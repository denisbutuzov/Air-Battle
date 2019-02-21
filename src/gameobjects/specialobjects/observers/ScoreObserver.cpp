#include <QGraphicsScene>

#include "Score.h"

#include "ScoreObserver.h"

ScoreObserver::ScoreObserver(Score *score)
    : subject_(score)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    subject_->attach(this);
}

void ScoreObserver::update()
{
    setPlainText(QString("Score: " + QString::number(subject_->score())));
}

void ScoreObserver::show(QGraphicsScene *scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
    update();
}
