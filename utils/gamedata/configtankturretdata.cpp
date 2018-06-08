#include "configtankturretdata.h"

const std::string ConfigTankTurretData::listNameInConfig_ = "game.tank.types";

ConfigTankTurretData::ConfigTankTurretData(
        const std::shared_ptr<Config> &config,
        const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
       logger_->printLog("ConfigTankTurretData is created", "[CONFIG]");
}

TankTurretInfo ConfigTankTurretData::getTurretInfoByType(TurretTypes type)
{
    TankTurretInfo info;
    std::string typenameByEnum;
    switch (type) {
    default:
        logger_->printLog("There is no such type of Turret, so DEFAULT type selected", "[GAME]");
        typenameByEnum = "default";
        break;
    }

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigTankTurretData is downloading", "[CONFIG]");
        int indexOfType = config_->findIndexOfType(listNameInConfig_, typenameByEnum);

        if (indexOfType == -1){
            std::string total = "No '" + typenameByEnum + "' in config in '" + listNameInConfig_ + "'\n";
            logger_->printLog(total, "[CONFIG]");
        }else {
            config_->lookup(listNameInConfig_, indexOfType, "turret.style.default_rect_pos", info.styleInfo.default_rect_pos);

            if (!info.styleInfo.default_rect_pos){
                config_->lookup(listNameInConfig_, indexOfType, "turret.style.x", info.styleInfo.x);
                config_->lookup(listNameInConfig_, indexOfType, "turret.style.y", info.styleInfo.y);
            }

            config_->lookup(listNameInConfig_, indexOfType, "turret.style.width", info.styleInfo.width);
            config_->lookup(listNameInConfig_, indexOfType, "turret.style.height", info.styleInfo.height);
            config_->lookup(listNameInConfig_, indexOfType, "turret.style.texture", info.styleInfo.pathToTexture);
            config_->lookup(listNameInConfig_, indexOfType, "turret.logic.speed_angle", info.turnSpeed);
            config_->lookup(listNameInConfig_, indexOfType, "turret.logic.bullet_recharge", info.rechargeSpeed);
        }
    }

    return info;
}

