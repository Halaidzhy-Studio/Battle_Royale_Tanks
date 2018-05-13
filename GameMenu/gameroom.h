#ifndef GAMEROOM_H
#define GAMEROOM_H

#include<string>

struct  GameRoom
{
public:
    GameRoom() = default;
    GameRoom(std::string roomName, short int maxPlayerCount, short int currentPlayerCount):
        roomName_(roomName), maxPlayerCount_(maxPlayerCount), currentPlayerCount_(currentPlayerCount){}

    ~GameRoom() = default;

    std::string roomName_;
    short int maxPlayerCount_;
    short int currentPlayerCount_;
};

#endif // GAMEROOM_H
