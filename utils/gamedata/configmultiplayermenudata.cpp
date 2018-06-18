#include "configmultiplayermenudata.h"


ConfigMultiplayerMenuData::ConfigMultiplayerMenuData(const std::shared_ptr<Config> &config,
                                                     const std::shared_ptr<Logger> &logger):
    ConfigExtractor(config, logger)
{
    std::string total = "ConfigMultiplayerMenuData is created";
    logger_->printLog(total, "[CONFIG]");
}

template<typename T>
void ConfigMultiplayerMenuData::lookupWrapper(const std::string &setting, T &var)
{
   std::string totalSetting = "windows.menu.menu_multiplayer." + setting;
   config_->lookup(totalSetting, var);
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
        lookupWrapper("btn_padding", info.btn_padding );
        lookupWrapper("back_btn_w", info.back_btn_w );
        lookupWrapper("back_btn_h_k", info.back_btn_h_k );
        lookupWrapper("start_btn_w", info.start_btn_w );
        lookupWrapper("start_btn_h_k", info.start_btn_h_k);
        lookupWrapper("txt_label_w", info.txt_label_w);
        lookupWrapper("txt_label_h_k", info.txt_label_h_k);
        lookupWrapper("prevt_btn_w", info.prevt_btn_w);
        lookupWrapper("prevt_btn_h_k", info.prevt_btn_h_k);
        lookupWrapper("nextt_btn_w", info.nextt_btn_w);
        lookupWrapper("nextt_btn_h_k", info.nextt_btn_h_k);
        config_->lookup("windows.menu.background_color", info.color);
    }
    return info;
}
