#pragma once

#include <QGraphicsTextItem>
#include <QGraphicsScene>

#include <memory>

#include "AbstractObserver.h"

constexpr const char *DEFAULT_TEXT = "Subject expired";

template<class T>
class LabelObserver
        : public QGraphicsTextItem
        , public AbstractObserver
{
public:
    LabelObserver(std::weak_ptr<T> subject, const QString &title);
    virtual void update() override;
    void show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate = QPointF(0.0, 0.0));
private:
    std::weak_ptr<T> subject_;
    QString title_;
};

template<class T>
LabelObserver<T>::LabelObserver(std::weak_ptr<T> subject, const QString &title)
    : subject_(subject)
    , title_(title)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    if(auto wp = subject_.lock())
    {
        wp->attach(this);
    }
}

template<class T>
void LabelObserver<T>::update()
{
    if(auto wp = subject_.lock())
    {
        setPlainText(title_ + QString::number(wp->value()));
    }
    else
    {
        setPlainText(DEFAULT_TEXT);
    }
}

template<class T>
void LabelObserver<T>::show(std::weak_ptr<QGraphicsScene> scene, QPointF coordinate)
{
    if(auto wp = scene.lock())
    {
        wp->addItem(this);
        setPos(coordinate);
        update();
    }
}
