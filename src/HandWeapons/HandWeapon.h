#pragma once

#include <QObject>
#include <QMediaPlayer>

#include <memory>

class QGraphicsScene;
class Gunshell;

class HandWeapon
        : public QObject
{
    Q_OBJECT

    friend class Equipment;

    struct Patrons
    {
        Patrons(): inMagazine(0), inStorage(0) {}
        unsigned int inMagazine;
        unsigned int inStorage;
    };
public:
    HandWeapon(std::weak_ptr<QGraphicsScene> scene, unsigned int capacity,
               unsigned int patrons, unsigned int shotDelay, const char *shotSound);
    virtual ~HandWeapon() = default;
    virtual bool unlimitedPatrons() const;
    unsigned int patronsInMagazine() const;
    unsigned int patronsInStorage() const;
    unsigned int capacity() const;
protected:
    std::weak_ptr<QGraphicsScene> scene() const;
private:
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    void reload();
    void addPatrons(unsigned int patrons);
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) = 0;
    void playShotSound();
private:
    std::weak_ptr<QGraphicsScene> scene_;
    Patrons patrons_;
    const unsigned int capacity_;
    const char *shotSound_;
    const unsigned int shotDelay_;
    bool shotDelayIsActive_;
    QMediaPlayer shotSoundPlayer_;
};
