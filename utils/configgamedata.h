#ifndef CONFIGGAMEDATA_H
#define CONFIGGAMEDATA_H

#include "gamedata.h"
#include "memory"
#include "logger.h"
#include <libconfig.h++>
using namespace libconfig;

class ConfigGameData : public GameData
{
public:
    ConfigGameData() { config_ = std::make_unique<Config>(); }
    ConfigGameData(const ConfigGameData&) = delete;
    ConfigGameData&operator= (const ConfigGameData&) = delete;
    ConfigGameData(ConfigGameData&& other) : config_(std::move(other.config_)) { }
    ~ConfigGameData() {}
    void upload(std::string configName);
private:
    std::unique_ptr<Config> config_;

    // GameData interface
public:
    TankInfo getTankInfoByType(TankTypes type) override;
    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
    TankTurretInfo getTurretInfoByType(TurretTypes type) override;
    BulletInfo getBulletInfoByType(BulletTypes type) override;
    MenuWindowInfo getMenuWindowInfo() override;
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;
};

#endif // CONFIGGAMEDATA_H
