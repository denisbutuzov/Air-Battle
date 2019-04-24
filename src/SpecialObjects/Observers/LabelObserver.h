#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsScene>

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

template<class T>
LabelObserver<T>::LabelObserver(T *subject, const QString &title)
    : subject_(subject)
    , title_(title)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    subject_->attach(this);
}

template<class T>
void LabelObserver<T>::update()
{
    setPlainText(title_ + QString::number(subject_->value()));
}

template<class T>
void LabelObserver<T>::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
    update();
}
