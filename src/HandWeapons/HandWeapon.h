#pragma once

#include <QObject>
#include <QMediaPlayer>

#include <memory>

class QGraphicsScene;
class Gunshell;

/*!
 * \defgroup Hand_weapons Виды ручного оружия
 * \brief Данный модуль описывает все виды ручного оружия, которые может
 * использовать игрок.
 */

/*!
 * \ingroup Hand_weapons
 * \brief Абстрактный родительский класс всех видов ручного оружия.
 *
 * Реализует класс ручного оружия, которое может использовать игрок.
 */
class HandWeapon
        : public QObject
{
    Q_OBJECT

    /*!
     * Для разрешения вызова метода `std::unique_ptr<Gunshell>
     * shoot(qreal x, qreal y)` объектом снаряжения, вызов которого в остальных случаях
     * нежелателен.
     */
    friend class Equipment;

    /*!
     * \brief Структура, реализующая оружейный магазин.
     */
    struct Magazine
    {
        Magazine(unsigned int capacity, unsigned int patrons)
            : capacity(capacity), patrons(patrons) {}
        const unsigned int capacity; ///<Емкость оружейного магазина
        unsigned int patrons; ///<Количество патронов в оружейном магазине
    };
public:
    ///Конструктор с пятью аргументами.
    HandWeapon(std::weak_ptr<QGraphicsScene> scene, unsigned int capacity,
               unsigned int patrons, unsigned int shotDelay, const QString &shotSound);
    ///Деструктор по умолчанию.
    virtual ~HandWeapon() = default;
    ///Метод, проверяющий на безлимитное количество патронов.
    virtual bool unlimitedPatrons() const;
    ///Метод, возвращающий количество патронов в оружейном магазине.
    unsigned int patronsInMagazine() const;
    ///Метод, возвращающий общее количество патронов.
    unsigned int patronsInStorage() const;
    ///Метод, возвращающий емкость оружейного магазина.
    unsigned int capacity() const;
    ///Метод для перезарядки оружия.
    void reload();
protected:
    ///Метод, возвращающий слабый указатель на объект сцены.
    std::weak_ptr<QGraphicsScene> scene() const;
private:
    ///Метод, реализующий выстрел.
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    ///Метод, реализующий загрузку в магазин.
    bool loadMagazine();
    ///Метод, реализующий добавление патонов.
    void addPatrons(unsigned int patrons);
    ///Метод, реализующий создание оружейного снаряда.
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) = 0;
    ///Метод для проигрывания мелодии выстрела.
    void playShotSound();
    ///Метод для проигрывания мелодии перезарядки.
    void playReloadSound();
private:
    std::weak_ptr<QGraphicsScene> scene_;
    Magazine magazine_;
    QMediaPlayer soundPlayer_;
    unsigned int patrons_;
    QString shotSound_;
    const unsigned int shotDelay_;
    bool shotDelayIsActive_;
    const unsigned int reloadDelay_;
    bool reloadDelayIsActive_;
};
