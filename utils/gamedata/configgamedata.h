#ifndef CONFIGGAMEDATA_H
#define CONFIGGAMEDATA_H

#include "gamedata.h"
#include "memory"
#include <utils/logger.h>
#include <libconfig.h++>

using namespace libconfig;

class ConfigGameData : public GameData, public std::enable_shared_from_this<ConfigGameData>
{
public:
    ConfigGameData() : configIsUpload(false) { config_ = std::make_shared<Config>(); }
    ConfigGameData(const ConfigGameData&) = delete;
    ConfigGameData&operator= (const ConfigGameData&) = delete;
    ConfigGameData(ConfigGameData&& other) : config_(std::move(other.config_)) { }
    ~ConfigGameData() {}
    void upload(std::string configName);
private:
    std::shared_ptr<Config> config_;
    bool configIsUpload;
    // GameData interface
public:
    TankInfo getTankInfoByType(TankTypes type) override;
    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
    TankTurretInfo getTurretInfoByType(TurretTypes type) override;
    BulletInfo getBulletInfoByType(BulletTypes type) override;
    MenuWindowInfo getMenuWindowInfo() override;
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;
    GameWindowInfo getGameWindowInfo() override;
    GameInfo getGameInfo() const override;

    std::shared_ptr<GameData> createGameData() override;
protected:
    ConfigGameData(std::string der, const std::shared_ptr<Config>& config ) : config_(config) { Logger::instance().printLog(der, Logger::loggerQt);  }

    template<class T>
    void lookup(const std::string &setting, T& var);
    void lookup(const std::string &setting, std::string &var);

private:
    std::unique_ptr<ConfigGameData> data_;
};
#endif // CONFIGGAMEDATA_H
