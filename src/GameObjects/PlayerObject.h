#pragma once

#include <set>

#include "GameObject.h"

class HandWeapon;
class HandBonus;
class Gunshell;
class Equipment;

/*!
 * \brief Класс объекта, управляемого игроком.
 *
 * Управляя объектом данного класса, игрок может:
 * - двигать объект в направлениях **вверх**, **вниз**, **вправо**, **влево**;
 * - стрелять из подобранного им в процессе игры оружия, перезаряжать и
 * менять оружие;
 * - использовать бонусы, подобранные в процессе игры.
 */
class PlayerObject
        : public QObject
        , public GameObject
{
    Q_OBJECT

public:
    ///Конструктор с одним аргументом.
    PlayerObject(std::weak_ptr<QGraphicsScene> scene);
    ///Деструктор по умолчанию.
    virtual ~PlayerObject() override;
    ///Метод, устанавливающий снаряжение.
    void setEquipment(std::shared_ptr<Equipment> equipment);
    ///Метод, добавляющий оружие в снаряжение.
    void takeWeapon(std::unique_ptr<HandWeapon> &&weapon);
    ///Метод, добавляющий бонус.
    void takeBonus(std::unique_ptr<HandBonus> &&bonus);
    ///Метод, реализующий выстрел.
    std::unique_ptr<Gunshell> shoot() const;
    ///Метод использования бонуса.
    void execute();
    ///Метод перезарядки оружия.
    void reloadWeapon();
    ///Метод смены оружия.
    void changeWeapon();
    ///Метод движения влево.
    void stepLeft();
    ///Метод движения вправо.
    void stepRight();
    ///Метод движения вверх.
    void stepUp();
    ///Метод движения вниз.
    void stepDown();
    ///Метод, реализующий логику при захвате события нажатия на кнопку.
    virtual void keyPressEvent(QKeyEvent *event) override final;
    ///Метод, реализующий логику при захвате события отпускания кнопки.
    virtual void keyReleaseEvent(QKeyEvent *event) override final;
signals:
    ///Сигнал, отправляемый при нажатии на кнопку выстрела.
    void shot_sig();
private:
    ///Метод, вызываемый по событию срабатывания внутреннего таймера объекта.
    virtual void timerEvent(QTimerEvent *event) override final;
private:
    std::set<Qt::Key> pressedKeys_;
    std::shared_ptr<Equipment> equipment_;
    bool pressKeysTimerAtWork_;
    std::unique_ptr<HandBonus> bonus_;
};
