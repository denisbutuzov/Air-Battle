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

    struct Magazine
    {
        Magazine(unsigned int capacity, unsigned int patrons)
            : capacity(capacity), patrons(patrons) {}
        const unsigned int capacity;
        unsigned int patrons;
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
    Magazine magazine_;
    unsigned int patrons_;
    const char *shotSound_;
    const unsigned int shotDelay_;
    bool shotDelayIsActive_;
    QMediaPlayer shotSoundPlayer_;
};
