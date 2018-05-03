#include "gameinstance.h"

GameInstance::GameInstance(const std::shared_ptr<libconfig::Config> config) : config_(config)
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

void GameInstance::updateTank()
{

}




