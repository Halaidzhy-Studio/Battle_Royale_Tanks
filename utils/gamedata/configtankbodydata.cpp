#include "configtankbodydata.h"

const std::string ConfigTankBodyData::listNameInConfig_ = "game.tank.types";

ConfigTankBodyData::ConfigTankBodyData(const std::shared_ptr<Config> &config,
                                       const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConfigTankBodyData is created", "[CONFIG]");
}


TankBodyInfo ConfigTankBodyData::getBodyInfoByType(BodyTypes type)
{
    TankBodyInfo info;

    std::string typenameByEnum;
    switch (type) {
    default:
        logger_->printLog("There is no such type of tank, so DEFAULT type selected", "[GAME]");
        typenameByEnum = "default";
        break;
    }

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigTankBodyData is downloading", "[CONFIG]");

        int indexOfType = config_->findIndexOfType(listNameInConfig_, typenameByEnum);
        if (indexOfType == -1){
            std::string total = "No '" + typenameByEnum + "' in config in '" + listNameInConfig_ + "'\n";
            logger_->printLog(total, "[CONFIG]");
        }else {
            config_->lookup(listNameInConfig_, indexOfType, "body.style.default_rect_pos", info.styleInfo.default_rect_pos);

            if (!info.styleInfo.default_rect_pos){
                config_->lookup(listNameInConfig_, indexOfType, "body.style.x", info.styleInfo.x);
                config_->lookup(listNameInConfig_, indexOfType, "body.style.y", info.styleInfo.y);
            }
            config_->lookup(listNameInConfig_, indexOfType, "body.style.width", info.styleInfo.width);
            config_->lookup(listNameInConfig_, indexOfType, "body.style.height", info.styleInfo.height);
            config_->lookup(listNameInConfig_, indexOfType, "body.style.texture", info.styleInfo.pathToTexture);
            config_->lookup(listNameInConfig_, indexOfType, "body.logic.speed", info.speed);
            config_->lookup(listNameInConfig_, indexOfType, "body.logic.speed_angle", info.turnSpeed);
            config_->lookup(listNameInConfig_, indexOfType, "body.logic.hp", info.hp);
        }
    }

    return info;
}

