#include <libconfig.h++>
#include "configextractorlibconfig.h"
#include "configmenuwindowdata.h"
#include "configsingleplayermenudata.h"
#include "configmultiplayermenudata.h"

void ConfigExtractorLibconfig::upload(const std::string& configName)
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

TankInfo ConfigExtractorLibconfig::getTankInfoByType(TankTypes type)
{
}

TankBodyInfo ConfigExtractorLibconfig::getBodyInfoByType(BodyTypes type)
{
}

TankTurretInfo ConfigExtractorLibconfig::getTurretInfoByType(TurretTypes type)
{
}

BulletInfo ConfigExtractorLibconfig::getBulletInfoByType(BulletTypes type)
{
}

MenuWindowInfo ConfigExtractorLibconfig::getMenuWindowInfo()
{
    data_.reset(new ConfigMenuWindowData(config_, logger_, configIsUpload_));
    return data_->getMenuWindowInfo();
}

SingleplayerMenuInfo ConfigExtractorLibconfig::getSingleplayerMenuInfo()
{

    data_.reset(new ConfigSingleplayerMenuData(config_, logger_, configIsUpload_));
    return data_->getSingleplayerMenuInfo();

}


MultiplayerMenuInfo ConfigExtractorLibconfig::getMultiplayerMenuInfo()
{
    data_.reset(new ConfigMultiplayerMenuData(config_, logger_, configIsUpload_));
    return data_->getMultiplayerMenuInfo();
}


GameWindowInfo ConfigExtractorLibconfig::getGameWindowInfo()
{
}

GameInfo ConfigExtractorLibconfig::getGameInfo() const
{
}


ServerInfo ConfigExtractorLibconfig::getServerInfo() const
{
}
