#include "ShieldDecorator.h"

/*!
 * \param enemy Указатель с исключительными правами владения объектом
 * врага для декорирования.
 * \param hitpoint Значение здоровья защитного щита.
 */
ShieldDecorator::ShieldDecorator(std::unique_ptr<Enemy> enemy,
                                 int hitpoint)
    : AbstractEnemyDecorator(std::move(enemy), hitpoint)
{
}

/*!
 * Добавляет защитный щит и декорируемого врага на объект сцены.
 */
void ShieldDecorator::init()
{
    initShield();
    AbstractEnemyDecorator::init();
}

/*!
 * Передвигает защитный щит вслед за передвижением декорируемого врага.
 */
void ShieldDecorator::move()
{
    auto pos1 = enemy()->pos();
    enemy()->move();
    auto deltaPos = enemy()->pos() - pos1;
    setPos(pos() + deltaPos);
}

/*!
 * Метод для автоматического расположения защитного щита перед декорируемым врагом.
 */
void ShieldDecorator::initShield()
{
    auto newPixmapWidth = enemy()->pixmap().width() * 1.2;
    setPixmap(pixmap().scaledToWidth(static_cast<int>(newPixmapWidth)));
    auto x = enemy()->pos().x() - newPixmapWidth * 0.1;
    auto y = enemy()->pos().y();
    setPos(x, y);
}
