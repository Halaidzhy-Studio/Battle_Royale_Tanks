#include "room.h"


Room::Room(quint32 id, QObject *parent)
    : QObject(parent),
      model(new RoomModel()),
      analyzer(new GameAnalyzer()),
      currentInterval(interval::FOR_GOOD_CONNECTION)
{
    connect(&waitingTimer, SIGNAL(timeout()), SLOT(start()));
    connect(&gameTimer, SIGNAL(timeout()), SLOT(update()));
    model->setRoomId(id);
}

Room::~Room()
{
    delete model;
    delete analyzer;
}

void Room::addNewUser(const QNetworkDatagram& datagram)
{
    model->setHost(datagram.senderAddress());
    model->setPackage(datagram.data());

    // отправить всем новый INIT-пакет
    model->createPackage(message::INIT);
    emit readySend(model->getRoomId());


    quint8 roomSize = model->getRoomSize();
    model->setRoomSize(++roomSize);

    if (roomSize == 1) {
        waitingTimer.start(WAITING_TIME);
    } else if (roomSize == model::MAX_SIZE) {
        emit isFull();
        start(); // досрочный старт, если все игроки зашли
    }
}

void Room::handleGameDatagram(const QNetworkDatagram &datagram)
{
    model->setPackage(datagram.data());
    checkConnection();
}


void Room::start()
{
    if (model->getRoomSize() == 1) {
        // сам с собой игрок играть не сможет
        emit isEmpty(model->getRoomId);
    }

    waitingTimer.stop();
    gameTimer.start(currentInterval);
}



void Room::update()
{
    model->createPackage(message::GAME);
    checkGameInteractions();
    emit readySend(model->getRoomId());
}


void Room::deleteUser(quint8 id)
{
    model->clearUserData(id);
    model->createPackage(message::CLOSE);
    emit readySend(model->getRoomId());

    quint8 roomSize = model->getRoomSize();
    model->setRoomSize(--roomSize);

    if (roomSize == 0 || roomSize == 1) {
        emit isEmpty(model->getRoomId());
    }
}

QList<QHostAddress>& Room::getHosts() const
{
    return model->getHosts();
}


QByteArray& Room::getData() const
{
    return model->getPackage();
}




void Room::invertInterval()
{
    currentInterval = (currentInterval == interval::FOR_GOOD_CONNECTION
                       ? interval::FOR_BAD_CONNECTION
                       : interval::FOR_GOOD_CONNECTION);
}


void Room::checkGameInteractions()
{
    // проверить попадания в танк

    // проверить столкновение с зоной

    // проверить пересечение снарядов (взаимоуничтожение)

    // проверить убитых
    // Если нет в живых (alives[id] = 0) и адрес не удален (т.е. игрок только что выбыл),
    // deleteUser(id);
}



void checkConnection() {

}







