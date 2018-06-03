#include "configsingleplayermenudata.h"

ConfigSingleplayerMenuData::ConfigSingleplayerMenuData(const std::shared_ptr<Config> &config,
                                                       const std::shared_ptr<Logger> &logger) :
    ConfigExtractor(config, logger)
{
    std::string total = "ConfigSingleplayerMenuData is created";
    logger_->printLog(total, "[CONFIG]");
}

SingleplayerMenuInfo ConfigSingleplayerMenuData::getSingleplayerMenuInfo()
{
    SingleplayerMenuInfo info;

    info.width = 600;
    info.height = 700;
    info.color = "white";
    info.btn_h_k = 5;
    info.btn_w_k = 5;
    info.btn_padding = 100;

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigSingleplayerMenuData is downloading config...", "[CONFIG]");
        config_->lookup("windows.menu.background_color", info.color);
        config_->lookup("windows.menu.width", info.width);
        config_->lookup("windows.menu.height", info.height);
        config_->lookup("windows.menu.menu_singleplayer.btn_h_k", info.btn_h_k);
        config_->lookup("windows.menu.menu_singleplayer.btn_w_k", info.btn_w_k);
        config_->lookup("windows.menu.menu_singleplayer.btn_padding", info.btn_padding);
    }

    return info;
}
