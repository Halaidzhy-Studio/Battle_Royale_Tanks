#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent),
      client(nullptr),
      clientData(new ClientData(100500))
{
    connect(&timer, SIGNAL(timeout()), SLOT(update()));
}

Controller::~Controller()
{
    delete clientData;
}


void Controller::createClient(QString cAddr, QString sAddr, quint16 crPort,
                              quint16 csPort, quint16 srPort, quint16 ssPort)
{
    client = new Client(cAddr, sAddr, crPort, csPort, srPort, ssPort);
    connect(client, SIGNAL(newReceivedDatagram()), SLOT(handleNewReceivedDatagram()));
}

void Controller::init()
{
    QByteArray data = clientData->createDataForNetwork(message::INIT);

    Header header;
    header.gameId = clientData->getGameId();
    header.message = message::INIT;

    client->setHeader(header);
    data = joinData(data, header);

    client->sendData(data);
}


void Controller::play()
{
    timer.start(interval::FOR_GOOD_CONNECTION);
}


void Controller::terminate()
{
    Header header = client->getHeader();

    if (header.message != message::CLOSE) {
        QByteArray data;
        header.message = message::CLOSE;
        client->setHeader(header);
        data = joinData(data, header);

        client->sendData(data);
    }

    delete client;

    clientData->clear();
}


QByteArray Controller::joinData(const QByteArray& data, const Header &header)
{
    QByteArray result;
    QDataStream out(&result, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out << header.gameId;
    out << header.roomId;
    out << header.userId;
    out << header.message;
    out << header.sequence;
    out << header.lastAck;
    out << header.prevAcks;

    out << data;

    return result;
}


void Controller::handleNewReceivedDatagram()
{
    while (client->hasDatagram()) {
        QByteArray data = client->receiveData();
        Header header = client->getHeader();
        quint8 type = header.message;

        clientData->setDataFromNetwork(data, type);

        switch (type) {
        case message::INIT:
        {
            header.message = message::INIT;
            client->setHeader(header);
            break;
        }

        case message::GAME:
        {
            header.message = message::GAME;
            header.roomId = clientData->getRoomId();
            header.userId = clientData->getUserId();
            client->setHeader(header);

            emit startGame();
            break;
        }

        case message::CLOSE:
        {
            header.message = message::CLOSE;
            client->setHeader(header);
            timer.stop();
            emit stopGame();
            break;
        }

        default:
            qDebug() << "MessageError";
            break;
        }
    }
}


void Controller::update()
{
    // из update() все сообщения уходят c message::GAME
    QByteArray data = clientData->createDataForNetwork(message::GAME);
    data = joinData(data, client->getHeader());
    client->sendData(data);
}










