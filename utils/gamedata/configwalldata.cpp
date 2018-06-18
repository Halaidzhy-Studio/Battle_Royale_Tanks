#include "configwalldata.h"

ConfigWallData::ConfigWallData(const std::shared_ptr<Config> &config,
                               const std::shared_ptr<Logger> &logger) : ConfigExtractor(config, logger)
{

}

template<typename T>
void ConfigWallData::lookupWrapper(const std::string &setting, T &var)
{
   std::string totalSetting = "game.wall." + setting;
   config_->lookup(totalSetting, var);
}

WallInfo ConfigWallData::getWallInfo()
{
    WallInfo info;
    info.h = 50;
    info.w = 50;
    info.physicsInfo.type = BodyType::StaticBody;
    info.styleInfo.pathToTexture = ":image/Resources/images/default_wall.png";
    info.styleInfo.default_rect_pos = true;
    info.styleInfo.x = 0;
    info.styleInfo.y = 0;
    info.styleInfo.opacity = 1;
    info.styleInfo.height = 50;
    info.styleInfo.width = 50;
    info.physicsInfo.h = 5;
    info.physicsInfo.w = 5;

    if (config_->isConfigUpload()){
        lookupWrapper("width", info.w);
        lookupWrapper("height", info.h);

        lookupWrapper("physics_w", info.physicsInfo.w);
        lookupWrapper("physics_h", info.physicsInfo.h);
        lookupWrapper("opacity", info.styleInfo.opacity);
        lookupWrapper("texture", info.styleInfo.pathToTexture);
        lookupWrapper("style_w", info.styleInfo.width);
        lookupWrapper("style_h", info.styleInfo.height);
        lookupWrapper("style_x", info.styleInfo.x);
        lookupWrapper("style_y", info.styleInfo.y);
        lookupWrapper("style_default_rect_pos", info.styleInfo.default_rect_pos);

        int indexType = 0;
        lookupWrapper("physics_type", indexType);
        info.physicsInfo.type = static_cast<BodyType>(indexType);

    }

    return info;
}
