#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "Player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    //create an item to put unto the scene
    Player *player = new Player();
    player->setRect(0, 0, 100, 100);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add the item to the scene
    scene->addItem(player);

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(800, 600);

    //place player on the view
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height());

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

    timer->start(2000);

    return a.exec();
}
