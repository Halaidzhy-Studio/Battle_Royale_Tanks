#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "client.h"
#include "clientdata.h"
#include "intervals.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void createClient(QString cAddr, QString sAddr, quint16 crPort,
                      quint16 csPort, quint16 srPort, quint16 ssPort);

    void init();
    void play();
    void terminate();

signals:
    void startGame();
    void stopGame();


public slots:
    void handleNewReceivedDatagram();
    void update();

private:
    QTimer timer;
    Client * client;
    ClientData * clientData;

    // Methods
    QByteArray joinData(const QByteArray& data, const Header& header);



};

#endif // CONTROLLER_H
