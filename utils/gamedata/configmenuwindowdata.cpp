#include "configmenuwindowdata.h"

MenuWindowInfo ConfigMenuWindowData::getMenuWindowInfo()
{
    MenuWindowInfo info;
    info.width = 600;
    info.height = 700;
    info.btn_part_size = 5;
    info.btn_w_k = 3;
    info.btn_h_k = 8;
    info.color = "white";

    if (configIsUpload_){
        logger_->printLog("ConfigMenuWindowData is downloading config...", "[CONFIG]");
        lookup("windows.menu.width", info.width);
        lookup("windows.menu.height", info.height);
        lookup("windows.menu.btn_part_size", info.btn_part_size);
        lookup("windows.menu.menu_main.btn_w_k", info.btn_w_k);
        lookup("windows.menu.menu_main.btn_h_k", info.btn_h_k);
        lookup("windows.menu.background_color", info.color);
    }
    return info;

}
