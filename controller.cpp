#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    connect(module, SIGNAL(newReceivedDatagram()), SLOT(handleNewDatagram()));
    createNewRoom();
}

Controller::~Controller()
{

}


void Controller::handleNewDatagram()
{
    while (module->hasDatagrams()) {
        QNetworkDatagram datagram = module->receive();
        Header header = getHeader(datagram.data());

        if (!isCorrectPackage(header))
            continue;

        switch (header.message) {
        case message::INIT:
            rooms[currentRoomId]->addNewUser(datagram);
            break;

        case message::GAME:
            rooms[header.roomId]->handleGameDatagram(datagram);
            break;

        case message::CLOSE:
            rooms[header.roomId]->deleteUser(header.userId);
            break;

        default:
            std::cerr << "MessageError" << std::endl;
            break;
        }
    }
}

void Controller::send(quint32 roomId)
{
    foreach (auto host, rooms[roomId]->getHosts()) {
        module->send(rooms[roomId]->getData(), host);
    }
}


void Controller::createNewRoom()
{
    // найти пустой ключ
    quint32 key = 0;
    while (!rooms[key].isEmpty())
        ++key;


    Room * room = new Room(key);
    connect(room, SIGNAL(readySend(quint32)), SLOT(send(quint32)));
    connect(room, SIGNAL(isFull()), SLOT(blockRoom()));
    connect(room, SIGNAL(isEmpty(quint32)), SLOT(removeRoom(quint32)));

    rooms[key] = room;
    currentRoomId = key;
}


// блокировать можно только текущую комнату
void Controller::blockRoom()
{
    rooms[currentRoomId]->block();
    createNewRoom();
}


void Controller::removeRoom(quint32 roomId)
{
    delete rooms[roomId];
    rooms->remove(roomId);
}


Header Controller::getHeader(const QByteArray& data) const
{
    QDataStream in(data, QIODevice::WriteOnly);
    in.setVersion(QDataStream::Qt_5_10);
    Header header;
    in >> header;
    if (in.status() == QDataStream::Ok)
        return header;
    else {
        std::cerr << "Error with writing header" << std::endl;
        Header empty;
        return empty;
    }
}


bool Controller::isCorrectPackage(const Header& header) const
{
    return header.gameId == GAME_ID;
}







