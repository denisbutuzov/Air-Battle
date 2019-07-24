#pragma once

#include <QObject>

#include "AbstractSubject.h"

constexpr unsigned int MAX_LEVEL = 5;

/*!
 * \ingroup Subjects
 * \brief Класс уровня в игре.
 *
 * Реализует класс уровня в игре.
 */
class Level
        : public QObject
        , public AbstractSubject
{
    Q_OBJECT

public:
    ///Конструктор с одним аргументом.
    explicit Level(unsigned int maxLevel = MAX_LEVEL);
    ///Метод, возвращающий значение текущего уровня в игре.
    unsigned int value() const;
public slots:
    ///Метод перехода на следующей уровень в игре.
    void increase();
private:
    unsigned int level_;
    unsigned int maxLevel_;
};
