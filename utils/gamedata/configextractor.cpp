#include <libconfig.h++>
#include "configextractor.h"
#include "configmenuwindowdata.h"
#include "configsingleplayermenudata.h"
#include "configmultiplayermenudata.h"
#include "configgameinfodata.h"
#include "configgamewindowdata.h"
#include "configtankbodydata.h"

ConfigExtractor::ConfigExtractor(const std::shared_ptr<Logger> &logger, const std::string &configFile) :
    logger_(logger), configFile_(configFile)
{
    config_ = std::make_shared<Config>(logger);
}

ConfigExtractor::ConfigExtractor(ConfigExtractor &&other)  :
    config_(std::move(other.config_)),
    logger_(std::move(other.logger_)),
    data_(std::move(other.data_))
{
}

void ConfigExtractor::upload()
{
    config_->upload(configFile_);
}

TankInfo ConfigExtractor::getTankInfoByType(TankTypes type)
{
}

TankBodyInfo ConfigExtractor::getBodyInfoByType(BodyTypes type)
{
    data_.reset(new ConfigTankBodyData(config_, logger_));
    return data_->getBodyInfoByType(type);
}

TankTurretInfo ConfigExtractor::getTurretInfoByType(TurretTypes type)
{
}

BulletInfo ConfigExtractor::getBulletInfoByType(BulletTypes type)
{
}

MenuWindowInfo ConfigExtractor::getMenuWindowInfo()
{
    data_.reset(new ConfigMenuWindowData(config_, logger_));
    return data_->getMenuWindowInfo();
}

SingleplayerMenuInfo ConfigExtractor::getSingleplayerMenuInfo()
{
    data_.reset(new ConfigSingleplayerMenuData(config_, logger_));
    return data_->getSingleplayerMenuInfo();
}


MultiplayerMenuInfo ConfigExtractor::getMultiplayerMenuInfo()
{
    data_.reset(new ConfigMultiplayerMenuData(config_, logger_));
    return data_->getMultiplayerMenuInfo();
}


GameWindowInfo ConfigExtractor::getGameWindowInfo()
{
    data_.reset(new ConfigGameWindowData(config_, logger_));
    return data_->getGameWindowInfo();
}

GameInfo ConfigExtractor::getGameInfo()
{
    data_.reset(new ConfigGameInfoData(config_, logger_));
    return data_->getGameInfo();
}


ServerInfo ConfigExtractor::getServerInfo()
{
}

CircleInfo ConfigExtractor::getCircleInfo()
{

}

ConfigExtractor::ConfigExtractor(const std::shared_ptr<Config> &config,
                                 const std::shared_ptr<Logger> &logger) :
    config_(config), logger_(logger)
{

}

