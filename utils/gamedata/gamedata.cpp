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

ServerInfo GameData::getServerInfo() const
{
    return serverInfo_;
}

std::shared_ptr<GameData> GameData::createGameData(const std::shared_ptr<Extractor> &extractor)
{
    std::shared_ptr<GameData> gameData(new GameData());

    extractor->upload();
    gameData->menuWindowInfo_ = extractor->getMenuWindowInfo();
    gameData->singleplayerMenuInfo_ = extractor->getSingleplayerMenuInfo();
    gameData->multiplayerMenuInfo_ = extractor->getMultiplayerMenuInfo();
    gameData->gameWindowInfo_ = extractor->getGameWindowInfo();
    gameData->gameInfo_ = extractor->getGameInfo();
    gameData->tankBodyInfoByType_[BodyTypes::DEFAULT] = extractor->getBodyInfoByType(BodyTypes::DEFAULT);

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

TankInfo GameData::getTankInfoByType(TankTypes type)
{
    return tankInfoByType_[type];
}

TankBodyInfo GameData::getBodyInfoByType(BodyTypes type)
{
    return tankBodyInfoByType_[type];
}

TankTurretInfo GameData::getTurretInfoByType(TurretTypes type)
{
    return tankTurretInfoByType_[type];
}

BulletInfo GameData::getBulletInfoByType(BulletTypes type)
{
    return bulletInfoByType_[type];
}
