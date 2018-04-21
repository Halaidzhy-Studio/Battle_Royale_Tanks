#include "gameinstance.h"

GameInstance::GameInstance() : gamePhysicsEngine_(new GamePhysicsEngineImpl())
{
    gameScene_ = new GameScene(gamePhysicsEngine_);
}

void GameInstance::renderInterface()
{
    showFullScreen();

}

void GameInstance::startGame()
{
    gameTimer_ = std::make_unique<QTimer>();

    connect(gameTimer_.get(), &QTimer::timeout, gameScene_, &GameScene::advance);
}


