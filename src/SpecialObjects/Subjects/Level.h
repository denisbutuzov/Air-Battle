#pragma once

#include <QObject>

#include "AbstractSubject.h"

constexpr unsigned int MAX_LEVEL = 4;

class Level
        : public QObject
        , public AbstractSubject
{
    Q_OBJECT

public:
    static Level *instance();
    unsigned int value() const;

public slots:
    void increase();

protected:
    Level(unsigned int maxLevel = MAX_LEVEL);
    Level(const Level &other) = delete;
    Level(Level &&other) = delete;

    Level &operator=(const Level &other) = delete;
    Level &operator=(Level &&other) = delete;

private:
    static Level *instance_;
    unsigned int level_;
    unsigned int maxLevel_;
};
