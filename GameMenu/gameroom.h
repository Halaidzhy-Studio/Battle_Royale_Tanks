#ifndef GAMEROOM_H
#define GAMEROOM_H

#include<QString>

class GameRoom
{
public:
    GameRoom() = default;

    GameRoom(QString roomName, quint8 maxPlayerCount, quint8 currentPlayerCount):
        roomName_(roomName), maxPlayerCount_(maxPlayerCount), currentPlayerCount_(currentPlayerCount){}

    ~GameRoom() = default;
    QString roomName() const;
    void setRoomName(const QString &roomName);

    quint8 maxPlayerCount() const;
    void setMaxPlayerCount(const quint8 &maxPlayerCount);

    quint8 currentPlayerCount() const;
    void setCurrentPlayerCount(const quint8 &currentPlayerCount);

private:
    QString roomName_;
    quint8 maxPlayerCount_;
    quint8 currentPlayerCount_;

};

#endif // GAMEROOM_H
