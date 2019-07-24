#pragma once

#include <list>

class AbstractObserver;

/*!
 * \defgroup Subjects Субъекты для наблюдения
 * \brief Данный модуль описывает все субъекты для наблюдения.
 */

/*!
 * \ingroup Subjects
 * \brief Абстрактный родительский класс всех субъектов для наблюдения.
 *
 * Реализует интерфейс субъекта для наблюдения:
 * - присоединение наблюдателя;
 * - отвязывание наблюдателя;
 * - оповещение наблюдателей.
 */
class AbstractSubject
{
public:
    ///Деструктор по умолчанию.
    virtual ~AbstractSubject() = default;
    ///Метод присоединения наблюдателя.
    virtual void attach(AbstractObserver *observer);
    ///Метод отвязывания наблюдателя.
    virtual void detach(AbstractObserver *observer);
    ///Метод оповещения наблюдателей.
    virtual void notify();
protected:
    ///Конструкто по умолчанию.
    AbstractSubject() = default;
private:
    std::list<AbstractObserver *> observers_;
};
