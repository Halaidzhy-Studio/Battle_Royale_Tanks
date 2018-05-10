#include "game.h"
#include "utils/logger.h"
#include "utils/data/menu/menuwindowinfostruct.h"

void Game::startGame()
{
    gameMenu_ = std::make_unique<GameMenu>(gameData_);
    gameMenu_->show();
}

void Game::onStart()
{
    Logger::instance().printLog("Game is start", "[ GAME ]");
}
