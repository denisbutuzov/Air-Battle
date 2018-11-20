#pragma once

#include <QGraphicsRectItem>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void spawn();
};
