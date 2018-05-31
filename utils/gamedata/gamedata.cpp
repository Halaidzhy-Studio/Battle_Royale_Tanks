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

std::shared_ptr<GameData> GameData::createGameData(const std::shared_ptr<ConfigExtractor> &extractor, const std::string &configPath)
{
    std::shared_ptr<GameData> gameData(new GameData());

    extractor->upload(configPath);
    gameData->menuWindowInfo_ = extractor->getMenuWindowInfo();
    gameData->singleplayerMenuInfo_ = extractor->getSingleplayerMenuInfo();
    gameData->multiplayerMenuInfo_ = extractor->getMultiplayerMenuInfo();
    gameData->serverInfo_ = extractor->getServerInfo();

    return gameData;
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
