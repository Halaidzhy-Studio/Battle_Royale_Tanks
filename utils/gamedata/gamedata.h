#ifndef GAMEDATA_H
#define GAMEDATA_H

#include<string>
#include <utils/data/windows/gamewindowinfostruct.h>
#include <utils/data/bodyinfostruct.h>
#include <utils/data/tankinfostruct.h>
#include <utils/data/bulletinfostruct.h>
#include <utils/data/menu/menuwindowinfostruct.h>
#include <utils/data/gameinfostruct.h>
#include <utils/gameobjectstypes.h>
#include <utils/data/network/serverinfo.h>
#include <memory>
#include <map>
#include "configextractor.h"
#include "QDebug"

class GameData
{
public:
    GameData() = default;
    ~GameData() = default;
    GameData(const GameData&) = delete;
    GameData&operator=(const GameData&) = delete;

    GameData(GameData&& other) noexcept :
        tankInfoByType_(std::move(other.tankInfoByType_)),
        tankBodyInfoByType_(std::move(other.tankBodyInfoByType_)),
        tankTurretInfoByType_(std::move(other.tankTurretInfoByType_)),
        bulletInfoByType_(std::move(other.bulletInfoByType_)),
        singleplayerMenuInfo_(std::move(other.singleplayerMenuInfo_)),
        multiplayerMenuInfo_(std::move(other.multiplayerMenuInfo_)),
        menuWindowInfo_(std::move(other.menuWindowInfo_)),
        gameWindowInfo_(std::move(other.gameWindowInfo_)),
        gameInfo_(std::move(other.gameInfo_)) { }

    TankInfo getTankInfoByType(TankTypes type);
    TankBodyInfo getBodyInfoByType(BodyTypes type);
    TankTurretInfo getTurretInfoByType(TurretTypes type);
    BulletInfo getBulletInfoByType(BulletTypes type);
    SingleplayerMenuInfo getSingleplayerMenuInfo() const;
    MultiplayerMenuInfo getMultiplayerMenuInfo() const;
    MenuWindowInfo getMenuWindowInfo() const;
    GameWindowInfo getGameWindowInfo() const;
    GameInfo getGameInfo() const;

    ServerInfo getServerInfo() const;

    static std::shared_ptr<GameData> createGameData(const std::shared_ptr<ConfigExtractor>& extractor,
                                             const std::string& configPath);

private:
    std::map<TankTypes, TankInfo> tankInfoByType_;
    std::map<BodyTypes, TankBodyInfo> tankBodyInfoByType_;
    std::map<TurretTypes, TankTurretInfo> tankTurretInfoByType_;
    std::map<BulletTypes, BulletInfo> bulletInfoByType_;

    SingleplayerMenuInfo singleplayerMenuInfo_;
    MultiplayerMenuInfo multiplayerMenuInfo_;
    MenuWindowInfo menuWindowInfo_;
    GameWindowInfo gameWindowInfo_;
    GameInfo gameInfo_;
    ServerInfo serverInfo_;

};

#endif // GAMEDATA_H

