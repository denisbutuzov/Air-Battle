#pragma once

#include <QGraphicsTextItem>

#include <memory>

#include "AbstractObserver.h"

template<class T>
class LabelObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    LabelObserver(T *subject, const QString &title);
    virtual void update() override;

    void show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate = QPointF(0.0, 0.0));

private:
    T *subject_;
    QString title_;
};
