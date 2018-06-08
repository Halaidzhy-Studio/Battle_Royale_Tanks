#include "gamedata.h"

SingleplayerMenuInfo GameData::getSingleplayerMenuInfo() const
{
    return singleplayerMenuInfo_;
}

MultiplayerMenuInfo GameData::getMultiplayerMenuInfo() const
{
    return multiplayerMenuInfo_;
}

MenuWindowInfo GameData::getMenuWindowInfo() const
{
    return menuWindowInfo_;
}

GameWindowInfo GameData::getGameWindowInfo() const
{
    return gameWindowInfo_;
}

GameInfo GameData::getGameInfo() const
{
    return gameInfo_;
}

CircleInfo GameData::getCircleInfo() const
{
    return circleInfo_;
}

std::string GameData::getMapFileByType(MapTypes type) const
{
    return mapFileByType_.at(type);
}

ServerInfo GameData::getServerInfo() const
{
    return serverInfo_;
}

std::shared_ptr<GameData> GameData::createGameData(const std::shared_ptr<Extractor> &extractor,
                                                   const std::shared_ptr<Logger> &logger)
{
    std::shared_ptr<GameData> gameData(new GameData());
    gameData->logger_ = logger;
    extractor->upload();
    gameData->menuWindowInfo_ = extractor->getMenuWindowInfo();
    gameData->singleplayerMenuInfo_ = extractor->getSingleplayerMenuInfo();
    gameData->multiplayerMenuInfo_ = extractor->getMultiplayerMenuInfo();
    gameData->gameWindowInfo_ = extractor->getGameWindowInfo();
    gameData->gameInfo_ = extractor->getGameInfo();

    gameData->tankBodyInfoByType_[BodyTypes::DEFAULT] = extractor->getBodyInfoByType(BodyTypes::DEFAULT);
    gameData->mapFileByType_[MapTypes::DEFAULT] = extractor->getMapFileByType(MapTypes::DEFAULT);
    gameData->tankTurretInfoByType_[TurretTypes::DEFAULT] = extractor->getTurretInfoByType(TurretTypes::DEFAULT);

    gameData->circleInfo_ = extractor->getCircleInfo();

    return gameData;
}

GameData::GameData(GameData &&other) noexcept :
    tankInfoByType_(std::move(other.tankInfoByType_)),
    tankBodyInfoByType_(std::move(other.tankBodyInfoByType_)),
    tankTurretInfoByType_(std::move(other.tankTurretInfoByType_)),
    bulletInfoByType_(std::move(other.bulletInfoByType_)),
    singleplayerMenuInfo_(std::move(other.singleplayerMenuInfo_)),
    multiplayerMenuInfo_(std::move(other.multiplayerMenuInfo_)),
    menuWindowInfo_(std::move(other.menuWindowInfo_)),
    gameWindowInfo_(std::move(other.gameWindowInfo_)),
    gameInfo_(std::move(other.gameInfo_))
{

}

TankInfo GameData::getTankInfoByType(TankTypes type) const
{

    return tankInfoByType_.at(type);
}

TankBodyInfo GameData::getBodyInfoByType(BodyTypes type) const
{
    TankBodyInfo info;
    try{
        info = tankBodyInfoByType_.at(type);
    }catch(const std::out_of_range& ex){
        logger_->printLog("No such type of TankBody", "[GAMEDATA]");
    }

    return info;
}

TankTurretInfo GameData::getTurretInfoByType(TurretTypes type) const
{
    TankTurretInfo info;
    try{
        info = tankTurretInfoByType_.at(type);
    }catch(const std::out_of_range& ex){
        logger_->printLog("No such type of TankTurret", "[GAMEDATA]");
    }
    return info;
}

BulletInfo GameData::getBulletInfoByType(BulletTypes type) const
{
    BulletInfo info;
    try{
        info = bulletInfoByType_.at(type);
    }catch(const std::out_of_range& ex){
        logger_->printLog("No such type of Bullet", "[GAMEDATA]");
    }
    return info;
}
