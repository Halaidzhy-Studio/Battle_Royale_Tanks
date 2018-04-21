#include "client.h"

Client::Client(QString cAddr, QString sAddr, quint16 crPort,
               quint16 csPort, quint16 srPort, quint16 ssPort,
               QObject *parent)
    : QObject(parent),
      receivingSocket(new QUdpSocket),
      sendingSocket(new QUdpSocket),
      clientHost(cAddr),
      serverHost(sAddr),
      clientReceivingPort(crPort),
      clientSendingPort(csPort),
      serverReceivingPort(srPort),
      serverSendingPort(ssPort)
{
    qDebug() << "Client()";

    if (!receivingSocket->bind(clientHost, clientReceivingPort)) {
        std::cerr << "Receiving socket is not available" << std::endl;
        exit(1);
    }

    if (!sendingSocket->bind(clientHost, clientSendingPort)) {
        std::cerr << "Sending socket is not available" << std::endl;
        exit(1);
    }

    connect(receivingSocket, SIGNAL(readyRead()), SIGNAL(newReceivedDatagram()));
}


Client::~Client()
{
    qDebug() << "~Client()";
    receivingSocket->deleteLater();
    sendingSocket->deleteLater();
}


void Client::setHeader(const Header &header)
{
    qDebug() << "setHeader()";

    this->header.gameId = header.gameId;
    this->header.roomId = header.roomId;
    this->header.userId = header.userId;
}


void Client::sendData(const QByteArray &data)
{
    sendingSocket->writeDatagram(data, serverHost, serverReceivingPort);
}


QByteArray Client::receiveData()
{
    QByteArray currentData;

    currentData = receivingSocket->receiveDatagram().data();

    Header currentHeader;
    QDataStream in(&currentData, QIODevice::ReadOnly);

    if (!checkDatagram(in, currentHeader)) {
        QByteArray arr;
        return arr;
    }

    return currentData;
}

bool Client::hasDatagram() const
{
    return receivingSocket->hasPendingDatagrams();
}

Header Client::getHeader() const
{
    return header;
}


bool Client::checkDatagram(QDataStream& in, Header& curHeader)
{
    in >> curHeader.gameId;
    in >> curHeader.roomId;
    in >> curHeader.userId;

    return (curHeader.gameId == header.gameId) &&
           (curHeader.roomId == header.roomId) &&
           (curHeader.userId == header.userId);
}



