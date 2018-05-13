#include "configgamedata.h"
#include "configmenuwindowdata.h"


void ConfigGameData::lookup(const std::string & setting, std::string& var){
    try{
        var = config_->lookup(setting).c_str();
    } catch(const SettingNotFoundException& ex){
        std::string totalMsg = "No '" + setting + "' in config file";
        Logger::instance().printLog(totalMsg, Logger::loggerGame);
    }
}

template<class T>
void ConfigGameData::lookup(const std::string &setting, T& var)
{
    try{
        var = config_->lookup(setting);
    } catch(const SettingNotFoundException& ex){
        std::string totalMsg = "No '" + setting + "' in config file";
        Logger::instance().printLog(totalMsg, Logger::loggerGame);
    }
}


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
    data_.reset(new ConfigMenuWindowData(config_));
    return data_->getMenuWindowInfo();
}



SingleplayerMenuInfo ConfigGameData::getSingleplayerMenuInfo()
{
    SingleplayerMenuInfo info;

    info.width = 600;
    info.height = 700;
    info.color = "white";
    info.btn_h_k = 5;
    info.btn_w_k = 5;
    info.btn_padding = 100;

    /*
    info.color = lookup<std::string>("windows.menu.background_color");
    info.width = lookup<decltype(info.width)>("windows.menu.width");
    */

    if (configIsUpload){
        lookup("windows.menu.background_color", info.color);
        lookup("windows.menu.width", info.width);
        lookup("windows.menu.height", info.height);
        lookup("windows.menu.menu_singleplayer.btn_h_k", info.btn_h_k);
        lookup("windows.menu.menu_singleplayer.btn_w_k", info.btn_w_k);
        lookup("windows.menu.menu_singleplayer.btn_padding", info.btn_padding);
    }
    /*
    try{
        config_->lookup("windows.menu.width");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.width' in config file " , "[CONFIG]");
    }

    try{
        config_->lookup("windows.menu.height");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.height' in config file " , "[CONFIG]");
    }

    try{
        config_->lookup("windows.menu.background_color");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.background_color' in config file " , "[CONFIG]");
    }

    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_h_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_h_k' in config file " , "[CONFIG]");
    }

    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_w_k");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_w_k' in config file " , "[CONFIG]");
    }

    try{
        config_->lookup("windows.menu.menu_singleplayer.btn_padding");
    } catch (const SettingNotFoundException& ex){
        Logger::instance().printLog("No 'windows.menu.menu_singleplayer.btn_padding' in config file " , "[CONFIG]");
    }*/

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


GameWindowInfo ConfigGameData::getGameWindowInfo()
{
}

GameInfo ConfigGameData::getGameInfo() const
{
}

/*
template<>
std::string ConfigGameData::lookup<std::string>(const std::string & setting){
    std::string var;
    try{
        var = config_->lookup(setting).c_str();
    } catch(const SettingNotFoundException& ex){
        std::string totalMsg = "No '" + setting + "' in config file";
        Logger::instance().printLog(totalMsg, Logger::loggerGame);
    }

    return var;
}

template<class T>
T ConfigGameData::lookup(const std::string &setting)
{
    T var;
    try{
        var = config_->lookup(setting);
    } catch(const SettingNotFoundException& ex){
        std::string totalMsg = "No '" + setting + "' in config file";
        Logger::instance().printLog(totalMsg, Logger::loggerGame);
    }

    return var;
}
*/

