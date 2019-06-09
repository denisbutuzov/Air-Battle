#pragma once

#include <QObject>

#include "AbstractSubject.h"

constexpr unsigned int MAX_LEVEL = 5;

class Level
        : public QObject
        , public AbstractSubject
{
    Q_OBJECT

public:
    explicit Level(unsigned int maxLevel = MAX_LEVEL);
    unsigned int value() const;
public slots:
    void increase();
private:
    unsigned int level_;
    unsigned int maxLevel_;
};
