#include <QDesktopWidget>
#include <QApplication>

/*!
 * \param wgt Виджет, положение которого требуется выравнить.
 *
 * Реализует выравнивание переданного в качестве аргумента виджета посередине экрана.
 */
void move_to_center(QWidget *wgt)
{
    QRect rect = wgt->geometry();
    rect.moveCenter(QApplication::desktop()->availableGeometry().center());
    wgt->setGeometry(rect);
}
