#include "game.h"
#include "utils/logger.h"
Game::Game(const std::shared_ptr<libconfig::Config> &config) : config_(config)
{

}

void Game::startGame()
{

    // default window size
    int width = 600, height = 700;
    try{
        width = config_->lookup("windows.menu.width");
    }catch(libconfig::SettingNotFoundException &ex){
        Logger::instance().printLog("No 'windows.menu.width' setting in configuration file", Logger::loggerGame);
    }

    try{
        height = config_->lookup("windows.menu.height");
    }catch(libconfig::SettingNotFoundException &ex){
        Logger::instance().printLog("No 'windows.menu.height' setting in configuration file", Logger::loggerGame);
    }

    gameMenu_ = std::make_unique<GameMenu>(width, height, config_);
    gameMenu_->show();
}
