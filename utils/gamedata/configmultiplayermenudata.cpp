#include "configmultiplayermenudata.h"


ConfigMultiplayerMenuData::ConfigMultiplayerMenuData(const std::shared_ptr<Config> &config,
                                                     const std::shared_ptr<Logger> &logger):
    ConfigExtractor(config, logger)
{
    std::string total = "ConfigMultiplayerMenuData is created";
    logger_->printLog(total, "[CONFIG]");
}

MultiplayerMenuInfo ConfigMultiplayerMenuData::getMultiplayerMenuInfo()
{
    MultiplayerMenuInfo info;
    info.width = 600;
    info.height = 700;
    info.btn_padding = 100;
    info.back_btn_w = 100;
    info.back_btn_h_k = 15;
    info.start_btn_w = 200;
    info.start_btn_h_k = 15;
    info.txt_label_w = 200;
    info.txt_label_h_k = 15;
    info.prevt_btn_w = 100;
    info.prevt_btn_h_k = 15;
    info.nextt_btn_w = 100;
    info.nextt_btn_h_k = 15;
    info.color = "white";

    if (config_->isConfigUpload()){
        logger_->printLog("ConfigMultiplayerMenuData is downloading config...", "[CONFIG]");
        config_->lookup("windows.menu.width", info.width);
        config_->lookup("windows.menu.height", info.height);
        config_->lookup("windows.menu.menu_multiplayer.btn_padding", info.btn_padding );
        config_->lookup("windows.menu.menu_multiplayer.back_btn_w", info.back_btn_w );
        config_->lookup("windows.menu.menu_multiplayer.back_btn_h_k", info.back_btn_h_k );
        config_->lookup("windows.menu.menu_multiplayer.start_btn_w", info.start_btn_w );
        config_->lookup("windows.menu.menu_multiplayer.start_btn_h_k", info.start_btn_h_k);
        config_->lookup("windows.menu.menu_multiplayer.txt_label_w", info.txt_label_w);
        config_->lookup("windows.menu.menu_multiplayer.txt_label_h_k", info.txt_label_h_k);
        config_->lookup("windows.menu.menu_multiplayer.prevt_btn_w", info.prevt_btn_w);
        config_->lookup("windows.menu.menu_multiplayer.prevt_btn_h_k", info.prevt_btn_h_k);
        config_->lookup("windows.menu.menu_multiplayer.nextt_btn_w", info.nextt_btn_w);
        config_->lookup("windows.menu.menu_multiplayer.nextt_btn_h_k", info.nextt_btn_h_k);
        config_->lookup("windows.menu.background_color", info.color);
    }
    return info;
}
