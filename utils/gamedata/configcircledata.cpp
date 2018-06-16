#include "configcircledata.h"

ConfigCircleData::ConfigCircleData(const std::shared_ptr<Config> &config,
                                   const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
}

CircleInfo ConfigCircleData::getCircleInfo()
{
    CircleInfo info;
    info.min_r = 100;
    info.max_r = 2000;
    info.r = 500;
    info.r_k = 100;
    info.simple_delay = 3;
    info.speed = 1;
    info.start_delay = 0;
    info.styleInfo.pathToTexture = ":image/Resources/images/Circle.png";

    config_->lookup("game.circle.min_r", info.min_r);
    config_->lookup("game.circle.max_r", info.max_r);
    config_->lookup("game.circle.r", info.r);
    config_->lookup("game.circle.r_k", info.r_k);
    config_->lookup("game.circle.simple_delay", info.simple_delay);
    config_->lookup("game.circle.speed", info.speed);
    config_->lookup("game.circle.start_delay", info.start_delay);
    config_->lookup("game.circle.texture", info.styleInfo.pathToTexture);

    return info;
}
