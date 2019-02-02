#pragma once

#include <QGraphicsView>

#include "PlayerObject.h"
#include "Health.h"
#include "AbstractLevelFactory.h"

class Game
        : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

private:
    SpawnObject *createSpawnObject(AbstractLevelFactory *factory);

private slots:
    void spawn();
    void levelChange();

private:
    QGraphicsScene *scene_;
    PlayerObject *player_;
    Health *health_;
    unsigned int level_;
};
