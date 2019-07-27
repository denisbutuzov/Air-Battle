#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsScene>

#include <memory>

#include "AbstractObserver.h"

constexpr const char *DEFAULT_TEXT = "Subject expired";

/*!
 * \ingroup Observers
 * \brief Класс простого текстового наблюдателя.
 *
 * Реализует наблюдатель, следящий за изменением численного поля
 * наблюдаемого класса.
 *
 * \warning Наблюдаемый класс должен иметь метод `value()`, возвращаемый
 * численное значение.
 */
template<class T>
class LabelObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    ///Конструктор с двумя аргументами.
    LabelObserver(std::weak_ptr<T> subject, const QString &title);
    ///Метод для обновления представления.
    virtual void update() override;
    ///Метод для отображения наблюдателя.
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    std::weak_ptr<T> subject_;
    QString title_;
};

/*!
  * \param subject Слабый указатель на наблюдаемый объект.
  * \param title Заголовок текста наблюдателя.
  *
  * Прикрепляет наблюдателя за объектом наблюдения, переданного
  * в качестве аргумента.
  */
template<class T>
LabelObserver<T>::LabelObserver(std::weak_ptr<T> subject, const QString &title)
    : subject_(subject)
    , title_(title)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
    }
}

/*!
 * Обновляет значение, соответствующее изменяемому полю
 * наблюдаемого класса.
 */
template<class T>
void LabelObserver<T>::update()
{
    if(auto wp = subject_.lock())
    {
        setPlainText(title_ + QString::number(wp->value()));
    }
    else
    {
        setPlainText(DEFAULT_TEXT);
    }
}

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param coordinate Позиция для отображения наблюдателя.
 *
 * Отображает объект наблюдателя на игровой сцене в позиции переданной
 * в качестве аргумента.
 */
template<class T>
void LabelObserver<T>::show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate)
{
    if(auto wp = scene.lock())
    {
        wp->addItem(this);
        setPos(coordinate);
        update();
    }
}
