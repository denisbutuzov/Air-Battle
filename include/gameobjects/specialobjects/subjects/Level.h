#pragma once

#include <QObject>

#include "AbstractSubject.h"

const uint16_t MAX_LEVEL = 3;

class Level
        : public QObject
        , public AbstractSubject
{
    Q_OBJECT

public:
    static Level *instance();
    uint16_t level() const;

public slots:
    void increase();

protected:
    Level(uint16_t maxLevel = MAX_LEVEL);
    Level(const Level &other) = delete;
    Level(Level &&other) = delete;

    Level &operator=(const Level &other) = delete;
    Level &operator=(Level &&other) = delete;

private:
    static Level *instance_;
    uint16_t level_;
    uint16_t maxLevel_;
};
