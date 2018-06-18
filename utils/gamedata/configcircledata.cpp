#include "configcircledata.h"

ConfigCircleData::ConfigCircleData(const std::shared_ptr<Config> &config,
                                   const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
}

template<typename T>
void ConfigCircleData::lookupWrapper(const std::string &setting, T &var)
{
   std::string totalSetting = "game.circle." + setting;
   config_->lookup(totalSetting, var);
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
    info.styleInfo.opacity = 1;
    info.styleInfo.pathToTexture = ":image/Resources/images/Circle.png";
    info.circleShape.opacity = 0.5;

    info.dmg = 1;
    info.check_interval = 1;
    info.center_x = 0;
    info.center_y = 0;
    info.styleInfo.is_scalable = false;

    if (config_->isConfigUpload()){
        lookupWrapper("min_r", info.min_r);
        lookupWrapper("max_r", info.max_r);
        lookupWrapper("r", info.r);
        lookupWrapper("r_k", info.r_k);
        lookupWrapper("simple_delay", info.simple_delay);
        lookupWrapper("speed", info.speed);
        lookupWrapper("start_delay", info.start_delay);
        lookupWrapper("shape_opacity", info.circleShape.opacity);
        lookupWrapper("dmg", info.dmg);
        lookupWrapper("check_interval", info.check_interval);
        lookupWrapper("center_x", info.center_x);
        lookupWrapper("center_y", info.center_y);
        lookupWrapper("is_scalable", info.styleInfo.is_scalable);
        lookupWrapper("texture", info.styleInfo.pathToTexture);
        lookupWrapper("opacity", info.styleInfo.opacity);
    }

    return info;
}
