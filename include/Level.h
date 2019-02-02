#pragma once

#include <QGraphicsTextItem>

class Level
        : public QGraphicsTextItem
{
    Q_OBJECT

public:
    Level(QGraphicsScene *scene_, QPointF coordinate);
    ~Level() = default;

    void init();
    unsigned int level() const;

public slots:
    void change();

private:
    unsigned int level_;
    QPointF coordinate_;
    QGraphicsScene *scene_;
};
