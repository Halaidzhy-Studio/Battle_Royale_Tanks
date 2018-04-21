#include "gamescene.h"

GameScene::GameScene(std::shared_ptr<GamePhysicsEngine>& gamePhysics) :
    gamePhysics_(gamePhysics)
{

}

void GameScene::advance()
{
    gamePhysics_->updateGame();
    QGraphicsScene::advance();
}
