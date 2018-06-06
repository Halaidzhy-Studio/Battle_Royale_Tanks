#ifndef CONFIGEXTRACTOR_H
#define CONFIGEXTRACTOR_H
#include<string>
#include <utils/data/windows/gamewindowinfostruct.h>
#include <utils/data/bodyinfostruct.h>
#include <utils/data/tankinfostruct.h>
#include <utils/data/bulletinfostruct.h>
#include <utils/data/menu/menuwindowinfostruct.h>
#include <utils/data/gameinfostruct.h>
#include <utils/gameobjectstypes.h>
#include <utils/data/network/serverinfo.h>
#include <utils/data/circleinfostruct.h>
class Extractor{
public:
    virtual ~Extractor() = default;

    virtual void upload() = 0;

    virtual TankInfo getTankInfoByType(TankTypes type) = 0;
    virtual TankBodyInfo getBodyInfoByType(BodyTypes type) = 0;
    virtual TankTurretInfo getTurretInfoByType(TurretTypes type) = 0;
    virtual BulletInfo getBulletInfoByType(BulletTypes type) = 0;
    virtual std::string getMapFileByType(MapTypes type) = 0;
    virtual SingleplayerMenuInfo getSingleplayerMenuInfo() = 0;
    virtual MultiplayerMenuInfo getMultiplayerMenuInfo () = 0;
    virtual MenuWindowInfo getMenuWindowInfo() = 0;
    virtual GameWindowInfo getGameWindowInfo() = 0;
    virtual GameInfo getGameInfo() = 0;
    virtual ServerInfo getServerInfo() = 0;
    virtual CircleInfo getCircleInfo() = 0;
};
#endif // CONFIGEXTRACTOR_H
