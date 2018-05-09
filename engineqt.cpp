#include "engineqt.h"

void EngineQT::setGameData(const std::shared_ptr<GameData> &gameData)
{
    gameData_ = gameData;
}

void EngineQT::setLogger(const std::shared_ptr<LoggerInterface> &)
{
    // Now logger is signleton
}

int EngineQT::startGame()
{
    game_ = std::make_shared<Game>(gameData_);
    game_->startGame();

    return this->exec();
}
