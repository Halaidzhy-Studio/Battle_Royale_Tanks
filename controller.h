#ifndef CONTROLLER_H
#define CONTROLLER_H

/* Главный класс, из него происходит все управление другими классами.
 * Проверяет пакеты, передает их в нужную комнату, получает от комнат пакеты
 * на отправку
 */

#include <QObject>
#include <QNetworkDatagram>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include "udpmodule.h"
#include "room.h"


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(UdpModule * module, QObject *parent = nullptr);
    ~Controller();

public slots:
    void handleNewDatagram();
    void send(quint32 roomId);
    void blockRoom();
    void removeRoom(quint32 roomId);

private:
    UdpModule * module;
    QHash<quint32, Room*> * rooms;
    quint32 currentRoomId;

    void createNewRoom();
    Header getHeader(const QByteArray& data) const;
    bool isCorrectPackage(const Header& header) const;
};

#endif // CONTROLLER_H
