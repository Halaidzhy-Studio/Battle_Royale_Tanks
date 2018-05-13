#include "engineqt.h"

void EngineQT::setGameData(const std::shared_ptr<GameData> &gameData)
{
    gameData_ = gameData;
}

void EngineQT::setLogger(const std::shared_ptr<Logger> &logger)
{
    logger_ = logger;
}

int EngineQT::startGame()
{
    game_ = std::make_shared<Game>(gameData_, logger_);
    game_->startMenu();
    return this->exec();
}
