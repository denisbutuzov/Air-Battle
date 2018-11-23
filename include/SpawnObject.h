#pragma once

#include <functional>

#include <QMap>
#include <QObject>
#include <QGraphicsPixmapItem>

class SpawnObject: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    void findCollidingItems(QMap<QGraphicsItem *, std::function<void> > &matching);
public slots:
    void move();
};
