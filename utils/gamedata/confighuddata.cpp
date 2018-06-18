#include "confighuddata.h"

ConfigHudData::ConfigHudData(
        const std::shared_ptr<Config> &config,
        const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConfigHudData is created", "[CONFIG]");
}

template<typename T>
void ConfigHudData::lookupWrapper(const std::string &setting, T &var)
{
   std::string totalSetting = "hud." + setting;
   config_->lookup(totalSetting, var);
}
HudInfo ConfigHudData::getHudInfo()
{
    HudInfo info;
    info.padding = 100;

    info.hp_image_x = -1;
    info.hp_image_y = -1;
    info.hp_image_h = 100;
    info.hp_image_w = 100;
    info.hp_image_path = ":image/Resources/images/HP.png";

    info.hp_count_x = -1;
    info.hp_count_y = -1;
    info.hp_count_h = 100;
    info.hp_count_w = 100;
    info.hp_count_value = -1;
    info.hp_count_text_size = 20;

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigHudData is downloading...", "[CONFIG]");

        lookupWrapper("hp_image_x", info.hp_image_x);
        lookupWrapper("hp_image_y", info.hp_image_y);
        lookupWrapper("hp_image_w", info.hp_image_w);
        lookupWrapper("hp_image_h", info.hp_image_h);
        lookupWrapper("hp_image_path", info.hp_image_path);

        lookupWrapper("hp_count_x", info.hp_count_x);
        lookupWrapper("hp_count_y", info.hp_count_y);
        lookupWrapper("hp_count_w", info.hp_count_w);
        lookupWrapper("hp_count_h", info.hp_count_h);
        lookupWrapper("hp_count_value", info.hp_count_value);
        lookupWrapper("hp_count_text_size", info.hp_count_text_size);

        lookupWrapper("bullet_image_x", info.bullet_image_x);
        lookupWrapper("bullet_image_y", info.bullet_image_y);
        lookupWrapper("bullet_image_w", info.bullet_image_w);
        lookupWrapper("bullet_image_h", info.bullet_image_h);
        lookupWrapper("bullet_image_path", info.bullet_image_path);

        lookupWrapper("bullet_time_x", info.bullet_time_x);
        lookupWrapper("bullet_time_y", info.bullet_time_y);
        lookupWrapper("bullet_time_w", info.bullet_time_w);
        lookupWrapper("bullet_time_h", info.bullet_time_h);
        lookupWrapper("bullet_time_value", info.bullet_time_value);
        lookupWrapper("bullet_time_text_size", info.bullet_time_text_size);

        lookupWrapper("circle_image_x", info.circle_image_x);
        lookupWrapper("circle_image_y", info.circle_image_y);
        lookupWrapper("circle_image_w", info.circle_image_w);
        lookupWrapper("circle_image_h", info.circle_image_h);
        lookupWrapper("circle_image_path", info.circle_image_path);

        lookupWrapper("circle_time_x", info.circle_time_x);
        lookupWrapper("circle_time_y", info.circle_time_y);
        lookupWrapper("circle_time_w", info.circle_time_w);
        lookupWrapper("circle_time_h", info.circle_time_h);
        lookupWrapper("circle_time_value", info.circle_time_value);
        lookupWrapper("circle_time_text_size", info.circle_time_text_size);
    }

    return info;
}


