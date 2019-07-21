#include <QLabel>

#include "Game.h"
#include "additionals.h"

#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->gameLabel->hide();
    move_to_center(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_startButton_clicked()
{
    gameStart();
}

void GameWindow::gamePause()
{
    showMsg("GAME PAUSE");
}

void GameWindow::gameOver()
{
    showMsg("GAME OVER");
    deleteGame();
}

void GameWindow::gameClose()
{
    ui->gameLabel->hide();
    show();
    deleteGame();
}

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

void GameWindow::showMsg(const char *msg)
{
    show();
    ui->gameLabel->setText(msg);
    ui->gameLabel->show();
}

void GameWindow::deleteGame()
{
    auto *temp = game_.release();
    delete temp;
}
