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
    info.physicsInfo.density = 1;
    info.physicsInfo.restitution = 0.1;
    info.physicsInfo.friction = 1.5;
    info.physicsInfo.linearDumping = 10.5;
    info.physicsInfo.w = 14;
    info.physicsInfo.h = 14;
    info.physicsInfo.type = BodyType::DynamicBody;

    std::string typenameByEnum;
    switch (type) {
    default:
        logger_->printLog("There is no such type of tank, so DEFAULT type selected", "[GAME]");
        typenameByEnum = GameData::DEFAULT_OBJECT_TYPE_NAME;
        break;
    }

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigTankBodyData is downloading", "[CONFIG]");

        int indexOfType = config_->findIndexOfType(listNameInConfig_, typenameByEnum);
        if (indexOfType == Config::NO_FINDED_INDEX){
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

            config_->lookup(listNameInConfig_, indexOfType, "body.physics.density", info.physicsInfo.density);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.friction", info.physicsInfo.friction);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.restitution", info.physicsInfo.restitution);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.linearDumping", info.physicsInfo.linearDumping);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.mass", info.physicsInfo.mass);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.I", info.physicsInfo.I);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.width", info.physicsInfo.w);
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.height", info.physicsInfo.h);

            int indexType = 0;
            config_->lookup(listNameInConfig_, indexOfType, "body.physics.type", indexType);
            info.physicsInfo.type = static_cast<BodyType>(indexType);
        }
    }

    return info;
}

