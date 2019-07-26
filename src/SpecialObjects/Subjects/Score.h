#pragma once

#include "AbstractSubject.h"

/*!
 * \ingroup Subjects
 * \brief Класс счета в игре.
 *
 * Реализует класс счета в игре.
 */
class Score
        : public AbstractSubject
{
public:
    ///Конструктор без аргументов.
    explicit Score();
    ///Метод увеличения счета в игре.
    void increase();
    ///Метод, возвращающий счет в игре.
    unsigned int value() const;
private:
    unsigned int score_;
};
