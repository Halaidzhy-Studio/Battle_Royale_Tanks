#ifndef CONFIGGAMEDATA_H
#define CONFIGGAMEDATA_H

#include "gamedata.h"
#include "memory"
#include <utils/logger.h>
#include "extractor.h"
#include <utils/config.h>

class ConfigExtractor : public Extractor, public std::enable_shared_from_this<ConfigExtractor>
{
public:
    ConfigExtractor(const std::shared_ptr<Logger>& logger, const std::string& configFile);

    ConfigExtractor(const ConfigExtractor&) = delete;
    ConfigExtractor&operator= (const ConfigExtractor&) = delete;

    ConfigExtractor(ConfigExtractor&& other);

    ~ConfigExtractor() = default;

    void upload() override;
    TankInfo getTankInfoByType(TankTypes type) override;
    TankBodyInfo getBodyInfoByType(BodyTypes type) override;
    TankTurretInfo getTurretInfoByType(TurretTypes type) override;
    BulletInfo getBulletInfoByType(BulletTypes type) override;
    std::string getMapFileByType(MapTypes type);
    MenuWindowInfo getMenuWindowInfo() override;
    SingleplayerMenuInfo getSingleplayerMenuInfo() override;
    MultiplayerMenuInfo getMultiplayerMenuInfo() override;
    GameWindowInfo getGameWindowInfo() override;
    GameInfo getGameInfo() override;
    ServerInfo getServerInfo() override;
    CircleInfo getCircleInfo() override;
    HudInfo getHudInfo() override;
    WorldPhysicsInfo getWorldPhysicsInfo() override;
    WallInfo getWallInfo() override;

private:
    // Переменная для хранения класса наследника
    std::unique_ptr<ConfigExtractor> data_;
    std::string configFile_;

protected:
    std::shared_ptr<Config> config_;
    std::shared_ptr<Logger> logger_;

    // Вызывает из наседников
    ConfigExtractor(const std::shared_ptr<Config>& config,
                   const std::shared_ptr<Logger>& logger);

};


#endif // CONFIGGAMEDATA_H
