#include <QTimer>

#include "GameObjects/Gunshells/Gunshell.h"
#include "AppSettings.h"

#include "HandWeapon.h"

/*!
 * \param scene Слабый указатель на объект сцены.
 * \param capacity Емкость ручного оружия.
 * \param patrons Количество патронов для ручного оружия.
 * \param shotDelay Задержка между выстрелами.
 * \param shotSound Путь к мелодии выстрела.
 *
 * Выполняет инициализацию полей и выполняет загрузку патронов в оружейным магазин.
 */
HandWeapon::HandWeapon(std::weak_ptr<QGraphicsScene> scene, unsigned int capacity,
                       unsigned int patrons, unsigned int shotDelay, const QString &shotSound)
    : scene_(scene)
    , magazine_(capacity, 0)
    , patrons_(patrons)
    , shotSound_(shotSound)
    , shotDelay_(shotDelay)
    , shotDelayIsActive_(false)
    , reloadDelay_(AppSettings::instance().objects().gun_.reloadDelay_)
    , reloadDelayIsActive_(false)
{
    loadMagazine();
}

/*!
 * \return false
 *
 * Возвращает true - если безлимитное количество патронов, false - в другом случаем.
 */
bool HandWeapon::unlimitedPatrons() const
{
    return false;
}

/*!
 * \return Количество патронов в оружейном магазине.
 */
unsigned int HandWeapon::patronsInMagazine() const
{
    return magazine_.patrons;
}

/*!
 * \return Общее количество патронов для ручного оружия.
 */
unsigned int HandWeapon::patronsInStorage() const
{
    return patrons_;
}

/*!
 * \return Емкость оружейного магазина.
 */
unsigned int HandWeapon::capacity() const
{
    return magazine_.capacity;
}

/*!
 * \param x Координата по оси Х на игровой сцене для порождения
 * оружейного снаряда.
 * \param y Координата по оси Y на игровой сцене для порождения
 * оружейного снаряда.
 *
 * \return Порожденный оружейный снаряд текущим оружием.
 *
 * Реализует выстрел из текущего оружия с порождением оружейного снаряда.
 */
std::unique_ptr<Gunshell> HandWeapon::shoot(qreal x, qreal y)
{
    if((unlimitedPatrons() || (patronsInMagazine() > 0) ) && !shotDelayIsActive_ && !reloadDelayIsActive_)
    {
        QTimer::singleShot(shotDelay_, [&](){ shotDelayIsActive_ = false; });
        shotDelayIsActive_ = true;
        if(magazine_.patrons > 0)
        {
            --magazine_.patrons;
        }
        playShotSound();
        return createGunshell(x, y);
    }
    return std::unique_ptr<Gunshell>();
}

/*!
 * \return Слабый указатель на объект сцены.
 */
std::weak_ptr<QGraphicsScene> HandWeapon::scene() const
{
    return scene_;
}

/*!
 * Рализует проигрывание мелодии выстрела.
 */
void HandWeapon::playShotSound()
{
    if(soundPlayer_.media().canonicalUrl() != QUrl(shotSound_))
    {
        soundPlayer_.setMedia(QUrl(shotSound_));
        soundPlayer_.play();
    }
    else
    {
        if(soundPlayer_.state() == QMediaPlayer::PlayingState)
        {
            soundPlayer_.setPosition(0);
        }
        else
        {
            soundPlayer_.play();
        }
    }
}

/*!
 * Реализует проигрывание мелодии перезарядки.
 */
void HandWeapon::playReloadSound()
{
    soundPlayer_.setMedia(QUrl(AppSettings::instance().objects().gun_.reloadSound_));
    soundPlayer_.play();
}

/*!
 * Реализует перезарядку ручного оружия.
 */
void HandWeapon::reload()
{
    if(!unlimitedPatrons())
    {
        QTimer::singleShot(reloadDelay_, [&](){ reloadDelayIsActive_ = false; });
        reloadDelayIsActive_ = true;
        if(loadMagazine())
        {
            playReloadSound();
        }
    }
}

/*!
 * \return Реализует загрузку патронов в оружейный магазин.
 */
bool HandWeapon::loadMagazine()
{
    if(patrons_ > 0 && magazine_.patrons < magazine_.capacity)
    {
        auto requiredPatrons = magazine_.capacity - magazine_.patrons;
        if(patrons_ >= requiredPatrons)
        {
            patrons_ -= requiredPatrons;
            magazine_.patrons += requiredPatrons;
        }
        else
        {
            magazine_.patrons += patrons_;
            patrons_ = 0;
        }
        return true;
    }
    return false;
}

/*!
 * \param patrons Количество патронов.
 *
 * Добавляет патроны к общему количеству для данного ручного оружия.
 */
void HandWeapon::addPatrons(unsigned int patrons)
{
    patrons_ += patrons;
}
