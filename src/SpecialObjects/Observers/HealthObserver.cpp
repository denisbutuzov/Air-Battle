#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "SpecialObjects/Subjects/Health.h"

#include "HealthObserver.h"

/*!
 * \param health Слабый указатель на объект здоровья игрока.
 * \param pixmap Путь до изображения, соответствующему единицы
 * здоровья игрока.
 *
 * Прикрепляет данный наблюдатель за объектом здоровья игрока,
 * переданного в качестве аргумента.
 */
HealthObserver::HealthObserver(std::weak_ptr<Health> health, const QString &pixmap)
    : subject_(health)
    , pixmap_(pixmap)
{
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
    }
}

/*!
 * Обновляет представление в соответсвии с количеством здоровья игрока.
 */
void HealthObserver::update()
{
    if(auto wp = subject_.lock())
    {
        auto tempVal = wp->value();
        if(static_cast<int>(hearts_.size()) < tempVal)
        {
            repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::addHeart, this), tempVal);
        }
        else
        {
            repeatWhileSizesAreNotEqual(std::bind(&HealthObserver::removeHeart, this), tempVal);
        }
    }
}

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param coordinate Позиция для отображения наблюдателя.
 *
 * Отображает объект наблюдателя на игровой сцене в позиции переданной
 * в качестве аргумента.
 */
void HealthObserver::show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate)
{
    scene_ = scene;
    coordinate_ = coordinate;

    if(!scene_.expired() && !subject_.expired())
    {
        auto tempVal = subject_.lock()->value();
        for (int i = 0; i != tempVal; ++i)
        {
            addHeart();
        }
    }
}

/*!
 * Добавляет изображение единицы здоровья на представление наблюдателя.
 */
void HealthObserver::addHeart()
{
    auto heart = std::make_unique<QGraphicsPixmapItem>(pixmap_);
    if(!hearts_.empty())
    {
        heart->setPos(hearts_.back()->pos() + QPointF(hearts_.back()->pixmap().width() + 5.0, 0.0));
    }
    else
    {
        heart->setPos(coordinate_);
    }
    scene_.lock()->addItem(heart.get());
    hearts_.push(std::move(heart));
}

/*!
 * Удаляет изображение единицы здоровья из представления наблюдателя.
 */
void HealthObserver::removeHeart()
{
    hearts_.pop();
}

/*!
 * \param callBack Функция для вызова.
 * \param value Значение наблюдателя.
 *
 * Обновляет представление наблюдателя в соответствии с некоторым значением
 * наблюдаемого объекта.
 */
void HealthObserver::repeatWhileSizesAreNotEqual(std::function<void ()> &&callBack, int value)
{
    while(static_cast<int>(hearts_.size()) != value)
    {
        callBack();
    }
}
