#include "confighuddata.h"

ConfigHudData::ConfigHudData(
        const std::shared_ptr<Config> &config,
        const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConfigHudData is created", "[CONFIG]");
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

        config_->lookup("hud.hp_image_x", info.hp_image_x);
        config_->lookup("hud.hp_image_y", info.hp_image_y);
        config_->lookup("hud.hp_image_w", info.hp_image_w);
        config_->lookup("hud.hp_image_h", info.hp_image_h);
        config_->lookup("hud.hp_image_path", info.hp_image_path);

        config_->lookup("hud.hp_count_x", info.hp_count_x);
        config_->lookup("hud.hp_count_y", info.hp_count_y);
        config_->lookup("hud.hp_count_w", info.hp_count_w);
        config_->lookup("hud.hp_count_h", info.hp_count_h);
        config_->lookup("hud.hp_count_value", info.hp_count_value);
        config_->lookup("hud.hp_count_text_size", info.hp_count_text_size);

        config_->lookup("hud.bullet_image_x", info.bullet_image_x);
        config_->lookup("hud.bullet_image_y", info.bullet_image_y);
        config_->lookup("hud.bullet_image_w", info.bullet_image_w);
        config_->lookup("hud.bullet_image_h", info.bullet_image_h);
        config_->lookup("hud.bullet_image_path", info.bullet_image_path);

        config_->lookup("hud.bullet_time_x", info.bullet_time_x);
        config_->lookup("hud.bullet_time_y", info.bullet_time_y);
        config_->lookup("hud.bullet_time_w", info.bullet_time_w);
        config_->lookup("hud.bullet_time_h", info.bullet_time_h);
        config_->lookup("hud.bullet_time_value", info.bullet_time_value);
        config_->lookup("hud.bullet_time_text_size", info.bullet_time_text_size);

        config_->lookup("hud.circle_image_x", info.circle_image_x);
        config_->lookup("hud.circle_image_y", info.circle_image_y);
        config_->lookup("hud.circle_image_w", info.circle_image_w);
        config_->lookup("hud.circle_image_h", info.circle_image_h);
        config_->lookup("hud.circle_image_path", info.circle_image_path);

        config_->lookup("hud.circle_time_x", info.circle_time_x);
        config_->lookup("hud.circle_time_y", info.circle_time_y);
        config_->lookup("hud.circle_time_w", info.circle_time_w);
        config_->lookup("hud.circle_time_h", info.circle_time_h);
        config_->lookup("hud.circle_time_value", info.circle_time_value);
        config_->lookup("hud.circle_time_text_size", info.circle_time_text_size);
    }

    return info;
}


