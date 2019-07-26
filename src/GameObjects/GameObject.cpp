#include <QGraphicsScene>

#include "GameObject.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 */
GameObject::GameObject(std::weak_ptr<QGraphicsScene> scene)
    :  scene_(scene)
{
}

/*!
 * \return Слабый указатель на объект сцены.
 */
std::weak_ptr<QGraphicsScene> GameObject::scene() const
{
    return scene_;
}

/*!
 * Добавляет объект на сцену, переданную в конструкторе.
 *
 * \warning Перед инициализацией объекта на сцене убедитесь, что для объекта
 * был вызван метод `void QGraphicsPixmapItem::setPixmap(const QPixmap & pixmap)`.
 * В противном случае метод вернет ошибку **You must to set a picture**.
 */
void GameObject::init()
{
    if(pixmap().isNull())
    {
        qFatal("You must to set a picture");
    }
    if(auto wp = scene_.lock())
    {
        wp->addItem(this);
    }
}
