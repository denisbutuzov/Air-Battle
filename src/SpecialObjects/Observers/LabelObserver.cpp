#include <QGraphicsScene>

#include "LabelObserver.h"

template<typename T>
LabelObserver<T>::LabelObserver(T *subject, const QString &title)
    : subject_(subject)
    , title_(title)
{
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20, QFont::Bold));
    subject_->attach(this);
}

template<typename T>
void LabelObserver<T>::update()
{
    setPlainText(title_ + QString::number(subject_->value()));
}

template<typename T>
void LabelObserver<T>::show(std::shared_ptr<QGraphicsScene> &scene, QPointF coordinate)
{
    scene->addItem(this);
    setPos(coordinate);
    update();
}
