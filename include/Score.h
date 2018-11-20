#pragma once

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
private:
    int score_;
public:
    Score(QGraphicsItem *parent = nullptr);
    void increase();
};
