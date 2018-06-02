#include "configgamewindowdata.h"

ConfigGameWindowData::ConfigGameWindowData(const std::shared_ptr<libconfig::Config>& config,
                     const std::shared_ptr<Logger>& logger,
                     bool configIsUpload) :
                     ConfigExtractorLibconfig(
                     config, logger, configIsUpload){

    logger_->printLog("ConGameWindowData is created", "[CONFIG]");
}

ConfigGameWindowData::~ConfigGameWindowData()
{

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

    if (configIsUpload_){
        logger_->printLog("ConGameWindowData is downloading", "[CONFIG]");
        lookup("windows.game_window.back_btn_height", info.back_btn_height);
        lookup("windows.game_window.back_btn_width", info.back_btn_width);
        lookup("windows.game_window.btn_padding", info.btn_padding);
        lookup("windows.game_window.is_full_screen", info.is_full_screen);
    }

    return info;
}
