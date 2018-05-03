#ifndef ROOMDATA_H
#define ROOMDATA_H

#include <QByteArray>
#include <QHash>
#include <QList>
#include <QHostAddress>
#include "messages.h"
#include "header.h"
#include "roomdata.h"

class RoomModel
{
public:
    RoomModel();
    QList<QHostAddress>& getHosts() const;
    void setHost(const QHostAddress& host);
    quint32 getRoomId() const;
    void setRoomId(const quint32& value);
    quint8 getRoomSize() const;
    void setRoomSize(const quint8& value);
    void setPackage(const QByteArray& data);
    QByteArray getPackage() const;
    void createPackage(quint8 type);
    void clearUserData(quint8 id);

private:
    quint32 roomId;
    quint8 roomSize;
    QHash<quint8, QHostAddress> hosts;
    QByteArray package; // новый сформированный пакет
    RoomData * data;

    quint8 generateUserId();
};

#endif // ROOMDATA_H
