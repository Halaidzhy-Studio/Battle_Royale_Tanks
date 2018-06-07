#include "configgameinfodata.h"

ConfigGameInfoData::ConfigGameInfoData(const std::shared_ptr<Config> &config,
                                       const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConfigGameInfoData is created", "[CONFIG]");
}

GameInfo ConfigGameInfoData::getGameInfo()
{
    GameInfo info;
    info.title = "Battle-royal-tanks";
    info.tick = 60;

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigGameInfoData is created", "[CONFIG]");
        config_->lookup("game.title", info.title);
        config_->lookup("game.tick", info.tick);
    }
    return info;
}
