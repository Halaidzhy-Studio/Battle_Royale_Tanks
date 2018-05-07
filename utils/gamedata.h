#ifndef GAMEDATA_H
#define GAMEDATA_H

#include<string>
#include "data/bodyinfostruct.h"
#include "data/tankinfostruct.h"
#include "data/bulletinfostruct.h"
#include "data/menu/menuwindowinfostruct.h"
#include "gameobjectstypes.h"

class GameData
{
public:
    virtual ~GameData() = default;
    virtual TankInfo getTankInfoByType(TankTypes type) = 0;
    virtual TankBodyInfo getBodyInfoByType(BodyTypes type) = 0;
    virtual TankTurretInfo getTurretInfoByType(TurretTypes type) = 0;
    virtual BulletInfo getBulletInfoByType(BulletTypes type) = 0;
    virtual SingleplayerMenuInfo getSingleplayerMenuInfo() = 0;
    virtual MultiplayerMenuInfo getMultiplayerMenuInfo () = 0;
    virtual MenuWindowInfo getMenuWindowInfo() = 0;
};


#endif // GAMEDATA_H
