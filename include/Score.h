#pragma once

#include <QGraphicsTextItem>

class Score:
        public QGraphicsTextItem
{
public:
    static Score *instance();
    void increase();
    void init(QGraphicsScene *scene);

protected:
    Score();

private:
    static Score *instance_;
    unsigned int score_;
};
