#include <QGraphicsScene>
#include <QKeyEvent>

#include <unordered_map>

#include "HandWeapons/HandWeapon.h"
#include "GameObjects/Gunshells/Gunshell.h"
#include "SpecialObjects/Subjects/Equipment.h"
#include "HandBonuses/HandBonus.h"

#include "PlayerObject.h"

/*!
 * \brief Переменная, определяющая часть игровой сцены, по которой
 * игрок не может перемещаться.
 *
 * \note Измените значение, чтобы определить размер новой области
 * для движения игрока.
 */
constexpr double INACTION_SCENE_PART = 0.66;

/*!
 * \param scene Слабый указатель на объект сцены.
 */
PlayerObject::PlayerObject(std::weak_ptr<QGraphicsScene> scene)
    : GameObject(scene)
    , pressKeysTimerAtWork_(false)
{
    equipment_ = std::make_unique<Equipment>(scene);
}

///Деструктор по умолчанию.
PlayerObject::~PlayerObject() = default;

/*!
 * \param equipment Указатель на разделяемый объект снаряжения.
 *
 * Устанавливает новое снаряжения для игрока.
 */
void PlayerObject::setEquipment(std::shared_ptr<Equipment> equipment)
{
    equipment_ = equipment;
}

/*!
 * \param weapon Указатель с исключительными правами владения объектом оружия.
 *
 * Добавляет новое оружие в снаряжения игрока.
 */
void PlayerObject::takeWeapon(std::unique_ptr<HandWeapon> &&weapon)
{
    equipment_->addWeapon(std::move(weapon));
}

/*!
 * \param bonus Указатель с исключительными правами владения объектом бонуса.
 *
 * Добавляет новый бонус игроку.
 */
void PlayerObject::takeBonus(std::unique_ptr<HandBonus> &&bonus)
{
    bonus_ = std::move(bonus);
}

/*!
 * \return Указатель с исключительными правами владения объектом оружейного снаряда.
 *
 * Делегирует обязанности выстрела (порождения объекта оружейного снаряда) объекту
 * снаряжения.
 */
std::unique_ptr<Gunshell> PlayerObject::shoot() const
{
    return equipment_->shoot(x() + pixmap().width()/2, y());
}

/*!
 * Использует бонус.
 */
void PlayerObject::execute()
{
    if(bonus_)
    {
        bonus_->execute();
    }
}

/*!
 * \param event Событие нажатия кнопки клавиатуры.
 *
 * Добавляет нажатую кнопку в список, обрабатываемый методом
 * `void PlayerObject::timerEvent(QTimerEvent *event)`.
 */
void PlayerObject::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        pressedKeys_.insert(static_cast<Qt::Key>(event->key()));
        if(!pressKeysTimerAtWork_)
        {
            startTimer(std::chrono::milliseconds(33));
            pressKeysTimerAtWork_ = true;
        }
    }
}

/*!
 * \param event Событие отпускания кнопки клавиатуры.
 *
 * Удаляет отпущенную кнопку из списка, обрабатываемого методом
 * `void PlayerObject::timerEvent(QTimerEvent *event)`.
 */
void PlayerObject::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        pressedKeys_.erase(static_cast<Qt::Key>(event->key()));
    }
}

/*!
 * \param event Событие срабатывания внутреннего таймера объекта.
 *
 * Обрабатывает все кнопки, нажатые игроком, реализуя множественные нажатия.
 */
void PlayerObject::timerEvent(QTimerEvent *event)
{
    static const std::unordered_map<Qt::Key, void(PlayerObject::*)(void)> FUNCTION_MAP
    {
        { Qt::Key_Left, &PlayerObject::stepLeft },
        { Qt::Key_Right, &PlayerObject::stepRight },
        { Qt::Key_Up, &PlayerObject::stepUp },
        { Qt::Key_Down, &PlayerObject::stepDown },
        { Qt::Key_Space, &PlayerObject::shot_sig },
        { Qt::Key_R, &PlayerObject::reloadWeapon },
        { Qt::Key_Shift, &PlayerObject::changeWeapon },
        { Qt::Key_E, &PlayerObject::execute }
    };

    if(pressedKeys_.empty())
    {
        killTimer(event->timerId());
        pressKeysTimerAtWork_ = false;
        return;
    }

    for(auto key : pressedKeys_)
    {
        auto it = FUNCTION_MAP.find(key);
        if(it != FUNCTION_MAP.end())
        {
            auto function = it->second;
            (this->*function)();

            if(key == Qt::Key_Shift)
            {
                pressedKeys_.erase(key);
            }
        }
    }
}

/*!
 * Реализует движения влево.
 */
void PlayerObject::stepLeft()
{
    if(x() > 0)
    {
        setPos(x() - 10, y());
    }
}

/*!
 * Реализует движения вправо.
 */
void PlayerObject::stepRight()
{
    if(scene().expired())
    {
        return;
    }
    if(x() + pixmap().width() < scene().lock()->width())
    {
        setPos(x() + 10, y());
    }
}

/*!
 * Реализует движения вверх.
 */
void PlayerObject::stepUp()
{
    if(scene().expired())
    {
        return;
    }
    if(y() > INACTION_SCENE_PART * scene().lock()->height())
    {
        setPos(x(), y() - 10);
    }
}

/*!
 * Реализует движения вниз.
 */
void PlayerObject::stepDown()
{
    if(scene().expired())
    {
        return;
    }
    if(y() < scene().lock()->height() - pixmap().height())
    {
        setPos(x(), y() + 10);
    }
}

/*!
 * Делегирует обязанности перезарядки оружия объекту снаряжения.
 */
void PlayerObject::reloadWeapon()
{
    equipment_->reloadWeapon();
}

/*!
 * Делегирует обязанности смены оружия объекту снаряжения.
 */
void PlayerObject::changeWeapon()
{
    equipment_->changeWeapon();
}
