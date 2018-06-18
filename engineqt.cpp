#include "engineqt.h"

EngineQT::EngineQT(int &argc, char **argv) : QApplication(argc, argv)
{
}

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
    gameMenu_ = std::make_unique<GameMenu>(gameData_, logger_);
    gameMenu_->show();
    return this->exec();
}
