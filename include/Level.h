#pragma once

#include <QGraphicsTextItem>

class Level
        : public QGraphicsTextItem
{
    Q_OBJECT

public:
    Level();
    ~Level() = default;

    void show(QGraphicsScene *scene_, QPointF coordinate = QPointF(0.0, 0.0));
    unsigned int level() const;

public slots:
    void change();

private:
    unsigned int level_;
};
