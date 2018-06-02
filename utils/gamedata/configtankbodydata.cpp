#include "configtankbodydata.h"

ConfigTankBodyData::ConfigTankBodyData()
{

}

ConfigTankBodyData::ConfigTankBodyData(const std::shared_ptr<libconfig::Config> &config,
                                       const std::shared_ptr<Logger> &logger,
                                       bool configIsUpload) :
    ConfigExtractorLibconfig(config, logger, configIsUpload)
{
    logger_->printLog("ConfigTankBodyData is created", "[CONFIG]");
}


TankBodyInfo ConfigTankBodyData::getBodyInfoByType(BodyTypes type)
{
    TankBodyInfo info;
    info.w = 40;
    info.h = 50;
    info.styleInfo.pathToTexture = "default.png";

    if (configIsUpload_){
        logger_->printLog("ConfigTankBodyData is downloading", "[CONFIG]");

    }
}
