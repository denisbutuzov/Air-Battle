#pragma once

/*!
 * \defgroup Observers Наблюдатели
 * \brief Данный модуль описывает все классы наблюдателей.
 */

/*!
 * \ingroup Observers
 * \brief Абстрактный родительский класс всех классов наблюдателей.
 *
 * Объявляет интерфейс классов наблюдателей.
 */
class AbstractObserver
{
public:
    ///Деструктор по умолчанию.
    virtual ~AbstractObserver() = default;
    ///Метод для обновления представления.
    virtual void update() = 0;
protected:
    ///Конструктор по умолчанию.
    AbstractObserver() = default;
};
