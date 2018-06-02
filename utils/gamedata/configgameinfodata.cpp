#include "configgameinfodata.h"

ConfigGameInfoData::ConfigGameInfoData(const std::shared_ptr<libconfig::Config> &config,
                                       const std::shared_ptr<Logger> &logger,
                                       bool configIsUpload) :
    ConfigExtractorLibconfig(config, logger, configIsUpload)
{
    logger_->printLog("ConfigGameInfoData is created", "[CONFIG]");
}

ConfigGameInfoData::~ConfigGameInfoData()
{
}


GameInfo ConfigGameInfoData::getGameInfo()
{
    GameInfo gameInfo;
    gameInfo.title = "Battle-royal-tanks";
    gameInfo.tick = 60;

    if (configIsUpload_){
        logger_->printLog("ConfigGameInfoData is downloading...", "[CONFIG]");
        lookup("game.title", gameInfo.title);
        lookup("game.tick", gameInfo.tick);
    }

    return gameInfo;
}
