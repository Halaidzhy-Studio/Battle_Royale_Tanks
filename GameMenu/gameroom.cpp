#include "gameroom.h"

QString GameRoom::roomName() const
{
    return roomName_;
}

void GameRoom::setRoomName(const QString &roomName)
{
    roomName_ = roomName;
}

quint8 GameRoom::maxPlayerCount() const
{
    return maxPlayerCount_;
}

void GameRoom::setMaxPlayerCount(const quint8 &maxPlayerCount)
{
    maxPlayerCount_ = maxPlayerCount;
}

quint8 GameRoom::currentPlayerCount() const
{
    return currentPlayerCount_;
}

void GameRoom::setCurrentPlayerCount(const quint8 &currentPlayerCount)
{
    currentPlayerCount_ = currentPlayerCount;
}
