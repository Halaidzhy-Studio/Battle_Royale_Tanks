#include "configgamewindowdata.h"


ConfigGameWindowData::ConfigGameWindowData(const std::shared_ptr<Config>& config,
                     const std::shared_ptr<Logger>& logger) :
    ConfigExtractor(config, logger)
{
    logger_->printLog("ConfigGameWindowData is created", "[CONFIG]");
}


template<typename T>
void ConfigGameWindowData::lookupWrapper(const std::string &setting, T &var)
{
   std::string totalSetting = "windows.game_window." + setting;
   config_->lookup(totalSetting, var);
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

    info.winlabel_w = 300;
    info.winlabel_h = 50;
    info.winlabel_txt = "You are winner :)";
    info.winlabel_txt_size = 30;
    info.loselabel_w = 300;
    info.loselabel_h = 50;
    info.loselabel_txt = "You are losser :(";
    info.loselabel_txt_size = 30;

    info.state_label_time = 3;

    if (config_->isConfigUpload()){
        logger_->printLog("ConGameWindowData is downloading", "[CONFIG]");
        lookupWrapper("back_btn_height", info.back_btn_height);
        lookupWrapper("back_btn_width", info.back_btn_width);
        lookupWrapper("btn_padding", info.btn_padding);
        lookupWrapper("is_full_screen", info.is_full_screen);
        lookupWrapper("width", info.width);
        lookupWrapper("height", info.height);
        lookupWrapper("back_btn_txt", info.back_btn_txt);
        lookupWrapper("winlabel_w", info.winlabel_w);
        lookupWrapper("winlabel_h", info.winlabel_h);
        lookupWrapper("winlabel_txt", info.winlabel_txt);
        lookupWrapper("winlabel_txt_size", info.winlabel_txt_size);
        lookupWrapper("loselabel_w", info.loselabel_w);
        lookupWrapper("loselabel_h", info.loselabel_h);
        lookupWrapper("loselabel_txt", info.loselabel_txt);
        lookupWrapper("loselabel_txt_size", info.loselabel_txt_size);
        lookupWrapper("state_label_time", info.state_label_time);
    }

    return info;
}
