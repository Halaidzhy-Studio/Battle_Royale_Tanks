#include "configgamedata.h"

#include "configmenuwindowdata.h"
#include "configsingleplayermenudata.h"
#include "configmultiplayermenudata.h"

void ConfigGameData::upload(std::string configName)
{
    try{
        config_->readFile(configName.c_str());
        configIsUpload_ = true;
    } catch ( const FileIOException &ex){
        std::string total = "I/O erorr while reading file: " + configName + " in " + __FUNCTION__;
        logger_->printLog(total, "[CONFIG]");
    } catch (const ParseException &ex){

        std::string total = "Parse error at " + std::string(ex.getFile()) + " : " + std::to_string(ex.getLine())
                + " - "  + ex.getError() + " in " + __FUNCTION__;
        logger_->printLog(total, "[CONFIG]");
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
    data_.reset(new ConfigMenuWindowData(config_, logger_, configIsUpload_));
    return data_->getMenuWindowInfo();
}

SingleplayerMenuInfo ConfigGameData::getSingleplayerMenuInfo()
{

    data_.reset(new ConfigSingleplayerMenuData(config_, logger_, configIsUpload_));
    return data_->getSingleplayerMenuInfo();

}


MultiplayerMenuInfo ConfigGameData::getMultiplayerMenuInfo()
{
    data_.reset(new ConfigMultiplayerMenuData(config_, logger_, configIsUpload_));
    return data_->getMultiplayerMenuInfo();
}


GameWindowInfo ConfigGameData::getGameWindowInfo()
{
}

GameInfo ConfigGameData::getGameInfo() const
{
}

std::shared_ptr<GameData> ConfigGameData::createGameData()
{
    return shared_from_this();
}
