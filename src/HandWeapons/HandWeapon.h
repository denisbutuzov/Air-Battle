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
               unsigned int patrons, unsigned int shotDelay, const QString &shotSound);
    virtual ~HandWeapon() = default;
    virtual bool unlimitedPatrons() const;
    unsigned int patronsInMagazine() const;
    unsigned int patronsInStorage() const;
    unsigned int capacity() const;
    void reload();
protected:
    std::weak_ptr<QGraphicsScene> scene() const;
private:
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    bool loadMagazine();
    void addPatrons(unsigned int patrons);
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) = 0;
    void playShotSound();
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
