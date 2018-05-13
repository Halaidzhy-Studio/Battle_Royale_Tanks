#include "game.h"
#include "utils/logger.h"
#include "utils/data/menu/menuwindowinfostruct.h"

Game::Game(const std::shared_ptr<GameData> &gameData,
           const std::shared_ptr<Logger>& logger) : gameData_(gameData), logger_(logger)
{
    gameWidget_ = std::make_unique<GameWidget>(gameData_, logger_);
    gameInfo_ = gameData_->getGameInfo();
}

void Game::startMenu()
{
    gameMenu_ = std::make_unique<GameMenu>(gameData_, shared_from_this(), logger_);
    gameMenu_->show();
}

void Game::startGame()
{
    gameWidget_->initInterface();

    gameTimer_ = std::make_unique<QTimer>();
    connect(gameTimer_.get(), &QTimer::timeout, this, &Game::update);

    gameTimer_->start(gameInfo_.gameTick);
    logger_->printLog("Game is started", "[ GAME ]");

}

void Game::endGame()
{   
    logger_->printLog("Game is ended", "[ GAME ]");
    emit backToMenuSignal();
}

void Game::update()
{
    for (auto& ob: objectsVector_)
        ob.update();
}

