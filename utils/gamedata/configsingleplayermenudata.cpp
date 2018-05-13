#include "configsingleplayermenudata.h"

SingleplayerMenuInfo ConfigSingleplayerMenuData::getSingleplayerMenuInfo()
{
    SingleplayerMenuInfo info;

    info.width = 600;
    info.height = 700;
    info.color = "white";
    info.btn_h_k = 5;
    info.btn_w_k = 5;
    info.btn_padding = 100;

    if (configIsUpload_){
        logger_->printLog("ConfigSingleplayerMenuData is downloading config...", "[CONFIG]");
        lookup("windows.menu.background_color", info.color);
        lookup("windows.menu.width", info.width);
        lookup("windows.menu.height", info.height);
        lookup("windows.menu.menu_singleplayer.btn_h_k", info.btn_h_k);
        lookup("windows.menu.menu_singleplayer.btn_w_k", info.btn_w_k);
        lookup("windows.menu.menu_singleplayer.btn_padding", info.btn_padding);
    }
    return info;
}
