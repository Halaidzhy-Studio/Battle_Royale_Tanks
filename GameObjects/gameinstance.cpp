#include "gameinstance.h"

GameInstance::GameInstance() : gamePhysicsEngine_(new GamePhysicsEngineImpl())
{
    gameScene_ = new GameScene(gamePhysicsEngine_);
}
