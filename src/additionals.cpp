#include <QDesktopWidget>
#include <QApplication>

void move_to_center(QWidget *wgt)
{
    QRect rect = wgt->geometry();
    rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    wgt->setGeometry(rect);
}
