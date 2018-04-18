#include "gameroom.h"

std::string GameRoom::roomName() const
{
    return roomName_;
}

void GameRoom::setRoomName(const std::string &roomName)
{
    roomName_ = roomName;
}

short int GameRoom::maxPlayerCount() const
{
    return maxPlayerCount_;
}

void GameRoom::setMaxPlayerCount(const short int &maxPlayerCount)
{
    maxPlayerCount_ = maxPlayerCount;
}

short int GameRoom::currentPlayerCount() const
{
    return currentPlayerCount_;
}

void GameRoom::setCurrentPlayerCount(const short int &currentPlayerCount)
{
    currentPlayerCount_ = currentPlayerCount;
}
