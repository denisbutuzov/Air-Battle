#pragma once

#include <memory>

class QWidget;

/*!
 * \file
 * \brief Файл вспомогательных функций.
 *
 * Файл включает в себя вспомогательные функции, используемые в коде игры.
 */

/*!
 * \brief Шаблон функции для динамического приведения указателя с правами исключительного
 * владения к другому.
 *
 * Реализует динамическое приведения указателя `std::unique_ptr<FromClass>` к указателю
 * `std::unique_ptr<ToClass>`. Если динамическое приведение невозможно, функция возвращает
 * указатель `std::unique_ptr<ToClass>`, инициализированный пустым указателем `nullptr`.
 */
template<typename ToClass, typename FromClass>
std::unique_ptr<ToClass> dynamic_unique_cast(std::unique_ptr<FromClass> &&from)
{
    if(ToClass *to = dynamic_cast<ToClass *>(from.get()))
    {
        std::unique_ptr<ToClass> result(to);
        from.release();
        return result;
    }
    return std::unique_ptr<ToClass>(nullptr);
}

///Функция для выравнивания виджета `QWidget` посередине экрана.
void move_to_center(QWidget *wgt);
