#include <QLabel>

#include "Game.h"
#include "additionals.h"

#include "GameWindow.h"
#include "ui_GameWindow.h"

/*!
 * \param parent Указатель на объект `QWidget`.
 *
 * Реализует инициализацию стартового окна игры.
 */
GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->gameLabel->hide();
    move_to_center(this);
}

/*!
 * Освобождает занятые ресурсы.
 */
GameWindow::~GameWindow()
{
    delete ui;
}

/*!
 * Запускает игру.
 */
void GameWindow::on_startButton_clicked()
{
    gameStart();
}

/*!
 * Отображает на стартовом окне игры сообщение **GAME PAUSE**.
 */
void GameWindow::gamePause()
{
    showMsg("GAME PAUSE");
}

/*!
 * Отображает на стартовом окне игры сообщение **GAME OVER**
 * и удаляет объект игры.
 */
void GameWindow::gameOver()
{
    showMsg("GAME OVER");
    deleteGame();
}

/*!
 * Реализует отображение стартового окна и удаления объекта игры.
 */
void GameWindow::gameClose()
{
    ui->gameLabel->hide();
    show();
    deleteGame();
}

/*!
 * Реализует запуск игры.
 */
void GameWindow::gameStart()
{
    if(game_.get() == nullptr)
    {
        game_ = std::make_unique<Game>();

        connect(game_.get(), SIGNAL(pause_sig()),
                this, SLOT(gamePause()));
        connect(game_.get(), SIGNAL(end_sig()),
                this, SLOT(gameOver()));
        connect(game_.get(), SIGNAL(close_sig()),
                this, SLOT(gameClose()));
    }
    hide();
    game_->start();
}

/*!
 * \param msg Сообщение для отображения на стартовом окне игры.
 */
void GameWindow::showMsg(const char *msg)
{
    show();
    ui->gameLabel->setText(msg);
    ui->gameLabel->show();
}

/*!
 * Реализует удаление объекта игры.
 */
void GameWindow::deleteGame()
{
    auto *temp = game_.release();
    delete temp;
}
