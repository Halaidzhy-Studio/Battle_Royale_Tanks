#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDataStream>
#include <QHostAddress>
#include <QByteArray>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include "header.h"


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QString cAddr, QString sAddr, quint16 crPort,
                    quint16 csPort, quint16 srPort, quint16 ssPort,
                    QObject * parent = nullptr);

    ~Client();

    Header getHeader() const;
    void setHeader(const Header& header);
    void sendData(const QByteArray& data);
    QByteArray receiveData();
    bool hasDatagram() const;

signals:
    void newReceivedDatagram();

private:
    QUdpSocket * receivingSocket;
    QUdpSocket * sendingSocket;
    QHostAddress clientHost;
    QHostAddress serverHost;
    quint16 clientReceivingPort;
    quint16 clientSendingPort;
    quint16 serverReceivingPort;
    quint16 serverSendingPort;
    Header header;


    bool checkDatagram(QDataStream& in, Header& curHeader);
    // void checkConnection();
};

#endif // CLIENT_H
