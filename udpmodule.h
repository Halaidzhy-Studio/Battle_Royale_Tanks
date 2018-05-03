#ifndef UDPMODULE_H
#define UDPMODULE_H

/*
 * UdpModule отвечает за всю техническую сторону сетевого обмена.
 * Представляет собой клиент - сервер, работающий по протоколу UDP.
 * Не содержит игровой логики.
 */

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QHostAddress>
#include <QDebug>
#include <iostream>

class UdpModule : public QObject
{
    Q_OBJECT
public:
    explicit UdpModule(quint16 rPort, quint16 sPort, QObject *parent = nullptr);
    ~UdpModule();
    void send(const QByteArray& data,  QString host);
    QNetworkDatagram receive();
    bool hasDatagrams() const;

signals:
    void newReceivedDatagram();

public slots:

private:
    QUdpSocket * receivingSocket;
    QUdpSocket * sendingSocket;
    quint16 receivingPort;
    quint16 sendingPort;
};

#endif // UDPMODULE_H
