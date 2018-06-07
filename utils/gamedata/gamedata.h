#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
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
#include <utils/gamedata/extractor.h>

class GameData
{
public:
    GameData() = default;
    ~GameData() = default;
    GameData(const GameData&) = delete;
    GameData&operator=(const GameData&) = delete;

    GameData(GameData&& other) noexcept;

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

    static std::shared_ptr<GameData> createGameData(const std::shared_ptr<Extractor>& extractor);

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

