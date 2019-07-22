#pragma once

#include "GameObjects/Enemies/Enemy.h"

/*!
 * \ingroup Game_objects
 * \brief Абстрактный родительский класс для всех декораторов врага.
 *
 * Реализует класс декораторов для врага.
 */
class AbstractEnemyDecorator
        : public Enemy
{
public:
    ///Деструктор по умолчанию.
    virtual ~AbstractEnemyDecorator() override = default;
    ///Метод инициализации врага и декоратора на сцене.
    virtual void init() override;
    ///Метод, возвращающий декорируемый объект врага.
    std::unique_ptr<Enemy> &enemy();
protected:
    ///Конструктор с двумя аргументами.
    AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy, int hitpoint);
private:
    std::unique_ptr<Enemy> enemy_;
};
