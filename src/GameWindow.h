#pragma once

#include <QMainWindow>

#include <memory>

class Game;

namespace Ui {
class GameWindow;
}

/*!
 * \brief Класс стартового окна игры.
 *
 * Реализует класс стартового окна игры.
 */
class GameWindow
        : public QMainWindow
{
    Q_OBJECT

public:
    ///Конструктор с одним аргументом.
    explicit GameWindow(QWidget *parent = nullptr);\
    ///Деструктор.
    ~GameWindow();
private slots:
    ///Метод, вызываемый при нажатии на кнопку начала игры.
    void on_startButton_clicked();
    ///Метод, вызываемый при постановке игры на паузу.
    void gamePause();
    ///Метод, вызываемый при завершении игры.
    void gameOver();
    ///Метод, вызываемый при закрытии окна игры.
    void gameClose();
private:
    ///Метод начала игры.
    void gameStart();
    ///Метод отображения сообщения.
    void showMsg(const char *msg);
    ///Метод удаления объекта игры.
    void deleteGame();
private:
    Ui::GameWindow *ui;
    std::unique_ptr<Game> game_;
};
