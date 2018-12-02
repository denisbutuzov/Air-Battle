#pragma once

#include <QGraphicsPixmapItem>

#include "GunShell.h"

class Weapon: public QGraphicsPixmapItem
{
private:
    GunShell *gunShell_;
public slots:
    void move();
};

