#pragma once

#include <QMainWindow>

#include <memory>

class Game;

namespace Ui {
class GameWindow;
}

class GameWindow
        : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
private slots:
    void on_startButton_clicked();
    void gamePause();
    void gameOver();
private:
    void gameStart();
    void showMsg(const char *msg);
private:
    Ui::GameWindow *ui;
    std::unique_ptr<Game> game_;
};
