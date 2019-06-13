#pragma once

#include <QTimer>
#include <QObject>

#include <memory>

class QGraphicsScene;
class Gunshell;

class HandWeapon
        : public QObject
{
    Q_OBJECT

public:
    HandWeapon(std::weak_ptr<QGraphicsScene> scene, int delayBetweenShots);
    virtual ~HandWeapon() = default;
    virtual std::unique_ptr<Gunshell> shoot(qreal x, qreal y) = 0;
    bool isReadyToShoot() const;
protected:
    std::weak_ptr<QGraphicsScene> scene() const;
    void startDelayBetweenShotsTimer();
private slots:
    void setReadyToShoot();
private:
    std::weak_ptr<QGraphicsScene> scene_;
    std::unique_ptr<QTimer> delayBetweenShotsTimer_;
    const int delayBetweenShots_;
    bool readyToShoot_;
};
