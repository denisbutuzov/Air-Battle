#include "AbstractEnemyDecorator.h"

/*!
 * \param enemy Указатель с исключительными правами владения объектом
 * врага для декорирования.
 * \param hitpoint Значение здоровья декоратора.
 */
AbstractEnemyDecorator::AbstractEnemyDecorator(std::unique_ptr<Enemy> enemy,
                                               int hitpoint)
    : Enemy(enemy->scene(), hitpoint, enemy->moveStrategy())
    , enemy_(std::move(enemy))
{
    setEnemyType(EnemyType::Decorator);
}

/*!
 * Добавляет декорируемый объект и декоратор на сцену.
 */
void AbstractEnemyDecorator::init()
{
    Enemy::init();
    enemy_->init();
}

/*!
 * \return Указатель с исключительными правами владения объектом декорируемого врага.
 */
std::unique_ptr<Enemy> &AbstractEnemyDecorator::enemy()
{
    return enemy_;
}
