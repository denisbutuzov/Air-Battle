#include <QApplication>

#include <ctime>

#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::srand(static_cast<uint16_t>(std::time(nullptr)));
    Game *game = new Game();
    game->show();

    return a.exec();
}
