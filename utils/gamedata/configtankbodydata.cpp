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
    info.w = 40;
    info.h = 50;
    info.styleInfo.pathToTexture = "default.png";

    std::string typenameByEnum;
    switch (type) {
    default:
        logger_->printLog("There is no such type of tank, so DEFAULT type selected", "[GAME]");
        typenameByEnum = "default";
        break;
    }

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigTankBodyData is downloading", "[CONFIG]");

        int indexOfType = findIndexOfType(typenameByEnum);
        if (indexOfType == -1){
            std::string total = "No '" + typenameByEnum + "' in config in '" + listNameInConfig_ + "'\n";
            logger_->printLog(total, "[CONFIG]");
        }else {
            config_->lookup(listNameInConfig_, indexOfType, "width", info.w);
            config_->lookup(listNameInConfig_, indexOfType, "height", info.h);
            config_->lookup(listNameInConfig_, indexOfType, "texture_body", info.styleInfo.pathToTexture);
            config_->lookup(listNameInConfig_, indexOfType, "speed", info.speed);
            config_->lookup(listNameInConfig_, indexOfType, "speed_angle", info.turnSpeed);
            config_->lookup(listNameInConfig_, indexOfType, "hp", info.hp);
        }
    }

    return info;
}

// Вынесу в конфиг класс, если будет время
int ConfigTankBodyData::findIndexOfType(const std::string& type){
    int lengthOfList = config_->getLengthOfList(listNameInConfig_);

    for (int i = 0; i < lengthOfList; i++){
        std::string tmp;
        config_->lookup(listNameInConfig_, i, "title", tmp);

        if (tmp == type)
            return i;
    }

    return -1;
}
