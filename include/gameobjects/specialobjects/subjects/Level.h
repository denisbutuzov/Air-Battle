#pragma once

#include <QObject>

#include "AbstractSubject.h"

const unsigned int MAX_LEVEL = 3;

class Level
        : public QObject
        , public AbstractSubject
{
    Q_OBJECT

public:
    static Level *instance();
    unsigned int level() const;

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
