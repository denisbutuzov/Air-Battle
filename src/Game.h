#pragma once

#include <QGraphicsView>
#include <QTimer>

#include <memory>

#include "GameObjectStorage.h"

template<typename T> class LabelObserver;
class HealthObserver;
class EquipmentObserver;
class PlayerObject;
class Level;
class Score;
class Health;

/*!
 * \brief Класс игры
 *
 * Реализует основные механизмы перераспределения запросов
 * между объектами.
 */
class Game
        : public QGraphicsView
{
    Q_OBJECT

public:
    ///Конструктор без аргументов.
    Game();
    ///Деструктор.
    ~Game() override;
public:
    ///Метод запуска игры.
    void start();
    ///Метод остановки игры.
    void pause();
signals:
    ///Сигнал, отправляемый во время паузы игры.
    void pause_sig();
    ///Сигнал, отправляемый во время окончания игры.
    void end_sig();
    ///Сигнал, отправляемый во время закрытия игры.
    void close_sig();
private slots:
    ///Метод перемещения игровых объектов.
    void moveGameObjects();
    ///Метод получения нового игрового объекта от менеджера игровых фабрик FactoryManager.
    void getSpawnObjectFromFactory();
    ///Метод получения оружейного снаряда от объекта игрока PlayerObject.
    void getGunshellFromPlayer();
    ///Метод удаления игровых объектов с игровой сцены.
    void removeObjectsFromScene();
    ///Метод проверяющий коллизии между объектами на игровой сцены.
    void checkCollisionBetweenGameObjects();
    ///Метод смены уровня в игре.
    void levelChange();
    ///Метод захвата события нажатия на кнопку.
    virtual void keyPressEvent(QKeyEvent *event) override;
    ///Метод захвата события отпускания кнопки.
    virtual void keyReleaseEvent(QKeyEvent *event) override;
private:
    ///Метод захвата события закрытия окна игры.
    virtual void closeEvent(QCloseEvent *event) override;
private:
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<Level> level_;
    std::shared_ptr<Score> score_;
    std::shared_ptr<Health> health_;
    std::unique_ptr<LabelObserver<Level>> levelObserver_;
    std::unique_ptr<LabelObserver<Score>> scoreObserver_;
    std::unique_ptr<HealthObserver> healthObserver_;
    std::unique_ptr<EquipmentObserver> equipmentObserver_;
    std::unique_ptr<PlayerObject> player_;
    GameObjectStorage objectsStorage_;
    QTimer spawnObjectTimer_;
    QTimer removeObjectTimer_;
    QTimer levelChangeTimer_;
    QTimer moveTimer_;
    QTimer checkCollisionTimer_;
};
