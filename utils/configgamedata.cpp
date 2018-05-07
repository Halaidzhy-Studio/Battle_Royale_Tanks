#include "configgamedata.h"


void ConfigGameData::upload(std::string configName)
{
    try{
        config_->readFile(configName.c_str());
    } catch ( const FileIOException &ex){
        std::string total = "I/O erorr while reading file: " + configName + " in " + __FUNCTION__;
        Logger::instance().printLog(total, "[CONFIG]");
    } catch (const ParseException &ex){

        std::string total = "Parse error at " + std::string(ex.getFile()) + " : " + std::to_string(ex.getLine())
                + " - "  + ex.getError() + " in " + __FUNCTION__;
        Logger::instance().printLog(total, "[CONFIG]");

    }
}

TankInfo ConfigGameData::getTankInfoByType(TankTypes type)
{
}

TankBodyInfo ConfigGameData::getBodyInfoByType(BodyTypes type)
{
}

TankTurretInfo ConfigGameData::getTurretInfoByType(TurretTypes type)
{
}

BulletInfo ConfigGameData::getBulletInfoByType(BulletTypes type)
{
}

MenuWindowInfo ConfigGameData::getMenuWindowInfo()
{
    MenuWindowInfo info;
    info.width = 600;
    try{
        config_->lookup("windows.menu.width");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.width' in config file " , "[CONFIG]");
    }

    info.height = 700;
    try{
        config_->lookup("windows.menu.height");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.height' in config file " , "[CONFIG]");
    }

    info.btn_part_size = 5;
    try{
        config_->lookup("windows.menu.btn_part_size");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.btn_part_size' in config file " , "[CONFIG]");
    }

    info.btn_w_k = 3;

    try{
        config_->lookup("windows.menu.menu_main.btn_w_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_main.btn_w_k' in config file " , "[CONFIG]");
    }

    info.btn_h_k = 8;
    try{
        config_->lookup("windows.menu.menu_main.btn_h_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_main.btn_h_k' in config file " , "[CONFIG]");
    }

    info.color = "white";
    try{
        config_->lookup("windows.menu.background_color");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.background_color' in config file " , "[CONFIG]");
    }

    return info;
}


SingleplayerMenuInfo ConfigGameData::getSingleplayerMenuInfo()
{
    SingleplayerMenuInfo info;

    info.width = 600;
    try{
        config_->lookup("windows.menu.width");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.width' in config file " , "[CONFIG]");
    }

    info.height = 700;
    try{
        config_->lookup("windows.menu.height");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.height' in config file " , "[CONFIG]");
    }

    info.color = "white";
    try{
        config_->lookup("windows.menu.background_color");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.background_color' in config file " , "[CONFIG]");
    }

    info.btn_h_k = 5;
    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_h_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_h_k' in config file " , "[CONFIG]");
    }

    info.btn_w_k = 5;
    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_w_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_w_k' in config file " , "[CONFIG]");
    }

    info.btn_padding = 100;

    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_padding");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_padding' in config file " , "[CONFIG]");
    }

    return info;
}


MultiplayerMenuInfo ConfigGameData::getMultiplayerMenuInfo()
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

    return info;
}
