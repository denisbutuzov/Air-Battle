#include <QLabel>

#include "Game.h"

#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->gameLabel->hide();
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
    auto *temp = game_.release();
    delete temp;
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
