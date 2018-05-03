#include "udpmodule.h"


UdpModule::UdpModule(quint16 rPort, quint16 sPort, QObject *parent)
    : QObject(parent),
      receivingSocket(new QUdpSocket),
      sendingSocket(new QUdpSocket),
      receivingPort(rPort),
      sendingPort(sPort)
{
    qDebug() << "UdpModule()";

    if (!receivingSocket->bind(receivingPort)) {
        std::cerr << "Receiving socket is not available" << std::endl;
        exit(1);
    }

    if (!sendingSocket->bind(sendingPort)) {
        std::cerr << "Sending socket is not available" << std::endl;
        exit(1);
    }

    connect(receivingSocket, SIGNAL(readyRead()), SIGNAL(newReceivedDatagram()));
}


UdpModule::~UdpModule()
{
    qDebug() << "~UdpModule()";
    receivingSocket->deleteLater();
    sendingSocket->deleteLater();
}


void UdpModule::send(const QByteArray &data, QString host)
{
    sendingSocket->writeDatagram(data, QHostAddress(host), receivingPort);
}


QByteArray UdpModule::receive()
{
    return receivingSocket->receiveDatagram();
}



bool UdpModule::hasDatagrams() const
{
    return receivingSocket->hasPendingDatagrams();
}








