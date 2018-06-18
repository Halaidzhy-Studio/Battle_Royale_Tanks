#include "configworldphysicsdata.h"


ConfigWorldPhysicsData::ConfigWorldPhysicsData(const std::shared_ptr<Config> &config,
                                               const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    logger->printLog("ConfigWorldPhysicsData is created", "[CONFIG]");
}

WorldPhysicsInfo ConfigWorldPhysicsData::getWorldPhysicsInfo()
{
    WorldPhysicsInfo info;
    info.gravity_x = 0;
    info.gravity_y = 0;
    info.position_iteration = 2;
    info.velocity_iteration = 6;
    info.time_step = 30;

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigWorldPhysicsData is downloading", "[CONFIG]");
        config_->lookup("box2d.world.time_step", info.time_step);
        config_->lookup("box2d.world.velocity_iteration", info.velocity_iteration);
        config_->lookup("box2d.world.position_iteration", info.position_iteration);
        config_->lookup("box2d.world.gravity_x", info.gravity_x);
        config_->lookup("box2d.world.gravity_y", info.gravity_y);
    }

    return info;
}
