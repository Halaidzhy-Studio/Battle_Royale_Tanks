#include "configmenuwindowdata.h"

ConfigMenuWindowData::ConfigMenuWindowData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger) :
                     ConfigExtractor(
                     config, logger){

    std::string total = "ConMenuWindowData is created";
    logger_->printLog(total, "[CONFIG]");
}

MenuWindowInfo ConfigMenuWindowData::getMenuWindowInfo()
{
    MenuWindowInfo info;
    info.width = 600;
    info.height = 700;
    info.btn_part_size = 5;
    info.btn_w_k = 3;
    info.btn_h_k = 8;
    info.color = "white";

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigMenuWindowData is downloading config...", "[CONFIG]");
        config_->lookup("windows.menu.width", info.width);
        config_->lookup("windows.menu.height", info.height);
        config_->lookup("windows.menu.btn_part_size", info.btn_part_size);
        config_->lookup("windows.menu.menu_main.btn_w_k", info.btn_w_k);
        config_->lookup("windows.menu.menu_main.btn_h_k", info.btn_h_k);
        config_->lookup("windows.menu.background_color", info.color);
    }
    return info;

}
