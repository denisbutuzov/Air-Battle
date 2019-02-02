#pragma once

#include <QGraphicsTextItem>

class Score:
        public QGraphicsTextItem
{
public:
    static Score *instance();
    void show(QGraphicsScene *scene);
    void increase();

protected:
    Score();
    Score(const Score &other) = delete;
    Score(Score &&other) = delete;

    Score &operator=(const Score &other) = delete;

private:
    static Score *instance_;
    unsigned int score_;
};
