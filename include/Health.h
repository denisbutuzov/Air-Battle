#pragma once

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
private:
    int health_;
public:
    Health(QGraphicsItem *parent = nullptr);
    void decrease();
};
