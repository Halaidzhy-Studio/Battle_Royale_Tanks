#ifndef ROOMDATA_H
#define ROOMDATA_H

#include <QMap>
#include <QBitArray>
#include "packages.h"

struct RoomData {
    Tank tanks[MAX_ROOM_SIZE];
    QMap<quint8, Bullet> bullets;
    Zone zone;
    QBitArray alives;  // битовый массив (жив / не жив)
};

#endif // ROOMDATA_H
