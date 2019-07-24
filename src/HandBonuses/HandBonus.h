#pragma once

class PlayerObject;
class GameObjectStorage;

/*!
 * \defgroup Hand_bonuses Ручные используемые бонусы
 * \brief Данный модуль описывает все ручные бонусы, которые может
 * использовать игрок.
 */

/*!
 * \ingroup Hand_bonuses
 * \brief Абстрактный родительский класс всех ручных используемых бонусов.
 *
 * Реализует класс ручного бонуса, который может использовать игрок.
 */
class HandBonus
{
public:
    ///Конструктор с двумя аргументами.
    HandBonus(PlayerObject *player, GameObjectStorage *storage);
    ///Деструктор по умолчанию.
    virtual ~HandBonus() = default;
    ///Метод использования бонуса.
    virtual void execute() = 0;
protected:
    ///Метод, возвращающий указатель на объект, управляемый игроком.
    PlayerObject *player() const;
    ///Метод, возвращающий указатель на объект хранилища игровых объектов.
    GameObjectStorage *storage() const;
private:
    PlayerObject *player_;
    GameObjectStorage *storage_;
};
