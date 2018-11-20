#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "Game.h"

Game::Game(QWidget *parent)
{
    //create a scene
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0, 0, 800, 600);

    //create an item to put unto the scene
    player_ = new Player();
    player_->setRect(0, 0, 100, 100);

    //make rect focusable
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    //add the item to the scene
    scene_->addItem(player_);

    //create the score
    score_ = new Score();
    scene_->addItem(score_);

    //add a view
    setScene(scene_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //place player on the view
    player_->setPos(width()/2 - player_->rect().width()/2, height() - player_->rect().height());

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player_, SLOT(spawn()));

    timer->start(2000);
}
