#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "MyRect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to put unto the scene
    MyRect *rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add the item to the scene
    scene->addItem(rect);

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();

    return a.exec();
}
