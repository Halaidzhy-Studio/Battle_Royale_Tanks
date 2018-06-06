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

    return info;
}
