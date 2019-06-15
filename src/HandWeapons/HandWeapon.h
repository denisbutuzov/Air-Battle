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

    using Cartridge = std::pair<int, int>;

public:
    HandWeapon(std::weak_ptr<QGraphicsScene> scene, int capacity,
               int patrons, int shotDelay, const char *shotSound);
    virtual ~HandWeapon() = default;
    std::unique_ptr<Gunshell> shoot(qreal x, qreal y);
    void reload();
    void addPatrons(int patrons);
protected:
    std::weak_ptr<QGraphicsScene> scene() const;
private:
    virtual std::unique_ptr<Gunshell> createGunshell(qreal x, qreal y) = 0;
    virtual bool patronsExist() const;
    void playShotSound();
private:
    std::weak_ptr<QGraphicsScene> scene_;
    Cartridge patrons_;
    const int capacity_;
    const int shotDelay_;
    QMediaPlayer shotSoundPlayer_;
    const char *shotSound_;
};
