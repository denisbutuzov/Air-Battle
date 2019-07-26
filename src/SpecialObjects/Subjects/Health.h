#pragma once

#include "AbstractSubject.h"

constexpr int MAX_HEALTH = 5;

/*!
 * \ingroup Subjects
 * \brief Класс здоровья игрока.
 *
 * Реализует класс здоровья игрока.
 */
class Health
        : public AbstractSubject
{
public:
    ///Конструктор с одним аргументом.
    explicit Health(int maxHealth = MAX_HEALTH);
    ///Метод увеличения здоровья игрока.
    void increase();
    ///Метод уменьшения здоровья игрока.
    void decrease();
    ///Метод, возвращающий значение здоровья игрока.
    int value() const;
private:
    int health_;
    int maxHealth_;
};
