#include "clientdata.h"

ClientData::ClientData(quint32 _gameId)
    : gameId(_gameId)
{
    alives.resize(MAX_PLAYERS);
}

// устанавливает поля класса из сырых данных
// в зависимости от типа сообщения
void ClientData::setDataFromNetwork(QByteArray &data, quint8 type)
{
    QDataStream in(&data, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_9);

    switch (type) {
    case message::INIT:
    {
        // распознан пакет ServerInitPackage

        in >> roomId;
        in >> userId;
        in >> roomSize;

        for (auto i = 0; i < roomSize; ++i) {
            quint8 id;
            in >> id;
            in >> tanks[id].type;

            quint8 nameSize;
            in >> nameSize;

            in >> tanks[id].name;
            assert(tanks[id].name.size() == nameSize);
        }

        assert(in.atEnd());
        break;
    }

    case message::GAME:
    {
        // распознан пакет ServerGamePackage

        for (int i = 0; i < roomSize; ++i) {
            quint8 id;
            in >> id;

            in >> tanks[id].centerX;
            in >> tanks[id].centerY;
            in >> tanks[id].hp;
            in >> tanks[id].tankRotation;
            in >> tanks[id].gunRotation;

            // TODO: Переопределить операторы >> и <<
        }

        in >> zone.leftTopX;
        in >> zone.leftTopY;
        in >> zone.rightBottomX;
        in >> zone.rightBottomY;
        in >> zone.zoneTimer;

        // установка битового массива
        quint32 bits;
        in >> bits;
        for (int i = 0; i < MAX_PLAYERS; ++i) {
            if (bits & 1)
                alives.setBit(i, 1);
            else
                alives.setBit(i, 0);

            bits >>= 1;
        }

        // установка данных об активных снарядах
        while (!in.atEnd()) {
            quint8 id;
            in >> id;

            bullets[id].tankId = id;
            in >> bullets[id].bulletX;
            in >> bullets[id].bulletY;
            in >> bullets[id].bulletRotation;
        }

        break;
    }

    default:
        qDebug() << "MessageError";
        // TODO: здесь бросать исключение
        break;
    }
}


// Возвращает тело для пакета типа type
QByteArray ClientData::createDataForNetwork(quint8 type) const
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);

    switch (type) {
    case message::INIT:
    {
        // формируем ClientInitPackage
        out << tankType;
        out << userName.size();
        out << userName.toStdString().data();
        break;
    }

    case message::GAME:
    {
        // формируем пакет ClientGamePackage
        // TankVolatileData
        out << tanks[userId].id;
        out << tanks[userId].centerX;
        out << tanks[userId].centerY;
        out << tanks[userId].hp;
        out << tanks[userId].tankRotation;
        out << tanks[userId].gunRotation;

        // снаряды
        QList<Bullet> lstBullet = getBulletsById(userId);
        out << (quint8) lstBullet.size();

        foreach (Bullet bullet, lstBullet) {
            out << bullet.tankId;
            out << bullet.bulletX;
            out << bullet.bulletY;
            out << bullet.bulletRotation;
        }

        break;
    }

    default:
        qDebug() << "MessageError";
        // TODO: здесь бросать исключение
        break;
    }

    return data;
}



quint32 ClientData::getGameId() const
{
    return gameId;
}

quint32 ClientData::getRoomId() const
{
    return roomId;
}

quint8 ClientData::getUserId() const
{
    return userId;
}

Tank ClientData::getTankById(quint8 id) const
{
    return tanks[id];
}

QList<Bullet> ClientData::getBulletsById(quint8 id) const
{
    return bullets.values(id);
}

void ClientData::setMyTank(const Tank &tank)
{
    tanks[userId] = tank;
}

void ClientData::setMyBullets(const QList<Bullet>& myBullets)
{
    foreach (auto bullet, myBullets)
        bullets[userId] = bullet;
}


void ClientData::setTankType(const quint8 &value)
{
    tankType = value;
}

void ClientData::clear()
{
    roomId = 0;
    userId = 0;
    roomSize = 0;
    tankType = 0;

    Tank emptyTank;
    for (auto i = 0; i < MAX_PLAYERS; ++i)
        tanks[i] = emptyTank;

    bullets.clear();

    Zone emptyZone;
    zone = emptyZone;

    alives.clear();
}

void ClientData::setUserName(const QString &value)
{
    userName = value;
}

QBitArray ClientData::getAlives() const
{
    return alives;
}

Zone ClientData::getZone() const
{
    return zone;
}

quint8 ClientData::getRoomSize() const
{
    return roomSize;
}


















