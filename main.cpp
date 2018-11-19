#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create an item to put unto the scene
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 100, 100);

    //add the item to the scene
    scene->addItem(rect);

    //add a view
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);

    view->show();

    return a.exec();
}
