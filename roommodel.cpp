#include "roommodel.h"

RoomModel::RoomModel()
    : data(new RoomData())
{
}

quint32 RoomModel::getRoomId() const
{
    return roomId;
}

void RoomModel::setRoomId(const quint32 &value)
{
    roomId = value;
}

quint8 RoomModel::getRoomSize() const
{
    return roomSize;
}

void RoomModel::setRoomSize(const quint8 &value)
{
    roomSize = value;
}
