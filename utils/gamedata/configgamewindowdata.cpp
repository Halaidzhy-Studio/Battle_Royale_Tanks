#include "configgamewindowdata.h"

ConfigGameWindowData::ConfigGameWindowData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConGameWindowData is created", "[CONFIG]");
}

GameWindowInfo ConfigGameWindowData::getGameWindowInfo()
{
    GameWindowInfo info;
    info.is_full_screen = true;
    info.width = -1;
    info.height = -1;
    info.back_btn_height = 50;
    info.back_btn_width = 50;
    info.btn_padding = 100;
    info.back_btn_txt = "Back";
    if (config_->isConfigUpload()){
        logger_->printLog("ConGameWindowData is downloading", "[CONFIG]");
        config_->lookup("windows.game_window.back_btn_height", info.back_btn_height);
        config_->lookup("windows.game_window.back_btn_width", info.back_btn_width);
        config_->lookup("windows.game_window.btn_padding", info.btn_padding);
        config_->lookup("windows.game_window.is_full_screen", info.is_full_screen);
        config_->lookup("windows.game_window.width", info.width);
        config_->lookup("windows.game_window.height", info.height);
        config_->lookup("windows.game_window.back_btn_txt", info.back_btn_txt);
    }

    return info;
}
