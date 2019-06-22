#include "Game.h"

#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    game_ = std::make_unique<Game>();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_startButton_clicked()
{
    game_->start();
}
