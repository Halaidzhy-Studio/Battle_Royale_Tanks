#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QTimer>
#include <QNetworkDatagram>
#include "roommodel.h"
#include "gameanalyzer.h"
#include "header.h"
#include "intervals.h"

const int WAITING_TIME = 10000;

class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(quint32 id, QObject *parent = nullptr);
    ~Room();

    void addNewUser(const QNetworkDatagram& datagram);
    void handleGameDatagram(const QNetworkDatagram& datagram);
    void deleteUser(quint8 id);
    QList<QHostAddress>& getHosts() const;
    QByteArray& getData() const;

signals:
    void readySend(quint32 roomId);
    void isFull();
    void isEmpty(quint32 roomId);

public slots:
    void start();
    void update();

private:
    RoomModel * model;
    GameAnalyzer * analyzer;
    QTimer waitingTimer;
    QTimer gameTimer;
    quint8 currentInterval;

    void invertInterval();
    void checkGameInteractions();
    void checkConnection();
};

#endif // ROOM_H
