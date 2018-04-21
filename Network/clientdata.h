#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <QString>
#include <QVector>
#include <QMap>
#include <QList>
#include <QByteArray>
#include <QBitArray>
#include <QDataStream>
#include <QDebug>
#include <assert.h>
#include "messages.h"
#include "packages.h"

class ClientData
{
public:
    explicit ClientData(quint32 gameId);
    quint32 getGameId() const;
    quint32 getRoomId() const;
    quint8 getUserId() const;
    quint8 getRoomSize() const;
    Zone getZone() const;
    QBitArray getAlives() const;
    void setDataFromNetwork(QByteArray& data, quint8 type);
    QByteArray createDataForNetwork(quint8 type) const;
    Tank getTankById(quint8 id) const;
    QList<Bullet> getBulletsById(quint8 id) const;
    void setMyTank(const Tank& tank);
    void setMyBullets(const QList<Bullet>& bullets);
    void setTankType(const quint8 &value);
    void setUserName(const QString &value);
    void clear();

private:
    const quint32 gameId;
    quint32 roomId;
    quint8 userId;
    quint8 roomSize;
    QString userName;
    quint8 tankType;

    Tank tanks[MAX_PLAYERS];
    QMap<quint8, Bullet> bullets;
    Zone zone;
    QBitArray alives;  // битовый массив (жив / не жив)
};



#endif // CLIENTDATA_H
