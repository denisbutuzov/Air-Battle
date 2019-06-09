#include "GameObjects/PlayerObject.h"
#include "GameObjects/MovableObject.h"
#include "GameObjects/Enemies/Enemy.h"
#include "SpecialObjects/Subjects/Level.h"
#include "Visitors/MoveVisitor.h"
#include "FactoryManager.h"

#include "Game.h"

constexpr int WINDOW_WIDTH = 600;
constexpr int WINDOW_HEIGHT = 800;
constexpr int SPAWN_OBJECT_PERIOD_MS = 2000;
constexpr int REMOVE_OBJECT_PERIOD_MS = 50;
constexpr int MOVE_OBJECT_PERIOD_MS = 50;
constexpr int LEVEL_CHANGE_PERIOD_MS = 10000;

constexpr const char *BACKGROUND_IMAGE = ":/images/images/Space.jpg";
constexpr const char *PLAYER_IMAGE = ":/images/images/Player.png";

Game::Game()
{
    scene_ = std::make_shared<QGraphicsScene>();
    scene_->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    setScene(scene_.get());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setBackgroundBrush(QBrush(QImage(BACKGROUND_IMAGE)));

    player_ = std::make_unique<PlayerObject>(scene_);
    player_->setPixmap(QPixmap(PLAYER_IMAGE));
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();
    player_->setPos((scene_->width() - player_->pixmap().width())/2,
                    scene_->height() - player_->pixmap().height());
    player_->init();

    level_ = std::make_shared<Level>();

    connect(&levelChangeTimer_, SIGNAL(timeout()),
            this, SLOT(levelChange()));
    levelChangeTimer_.start(LEVEL_CHANGE_PERIOD_MS);

    connect(&spawnObjectTimer_, SIGNAL(timeout()),
            this, SLOT(getSpawnObjectFromFactory()));
    spawnObjectTimer_.start(SPAWN_OBJECT_PERIOD_MS);

    connect(&removeObjectTimer_, SIGNAL(timeout()),
            this, SLOT(removeObjectsFromScene()));
    removeObjectTimer_.start(REMOVE_OBJECT_PERIOD_MS);

    connect(&moveTimer_, SIGNAL(timeout()),
            this, SLOT(moveGameObjects()));
    moveTimer_.start(MOVE_OBJECT_PERIOD_MS);
}

void Game::moveGameObjects()
{
    MoveVisitor visitor;
    for(auto &obj : objects_)
    {
        visitor.visitEnemy(dynamic_cast<Enemy *>(obj.get()));
    }
}

void Game::getSpawnObjectFromFactory()
{
    auto spawnObject = FactoryManager::createSpawnObject(scene_, level_);
    spawnObject->init();
    objects_.push_back(std::move(spawnObject));
}

void Game::removeObjectsFromScene()
{
    objects_.remove_if([&](auto &obj){ return obj->y() > scene_->height(); });
}

void Game::levelChange()
{
    level_->increase();
}

Game::~Game() = default;
