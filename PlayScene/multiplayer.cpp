#include <QTime>
#include <QDebug>

#include "multiplayer.h"

Multiplayer::Multiplayer(QWidget *parent, GameRoom* gameRoom): QWidget(parent), gameRoom_(gameRoom)
{

    setAttribute(Qt::WA_DeleteOnClose);
}

Multiplayer::~Multiplayer()
{
    delete gameRoom_;
}

qint16 Multiplayer::roomNumber() const
{
    return roomNumber_;
}

void Multiplayer::setRoomNumber(const qint16 &roomNumber)
{
    roomNumber_ = roomNumber;
}

void Multiplayer::renderGame()
{
    backToMultiplayerMenuBTN_ = new QPushButton("Back", this);
    backToMultiplayerMenuBTN_->resize(100, 100);

    connect(backToMultiplayerMenuBTN_, &QPushButton::released, this, &Multiplayer::onBackToMultiplayerMenu);
}

void Multiplayer::onBackToMultiplayerMenu(){
    close();
    emit multiplayerMenu();
}

void Multiplayer::startGame()
{

    sendPackageTimer_ = new QTimer();
    connect(sendPackageTimer_, &QTimer::timeout, this, &Multiplayer::onSetSendingPackage);

    sendPackageTimer_->start(1000);

}


void Multiplayer::onBadConnection()
{
    sendPackageTimer_->setInterval(5000);
}

void Multiplayer::onGoodConnection()
{
    sendPackageTimer_->stop();
    sendPackageTimer_->start(1000/30);
}

void Multiplayer::onGetReceivingPackage()
{
    qDebug() << __FUNCTION__ << QTime::currentTime().toString() << "\n";
}

void Multiplayer::onSetSendingPackage()
{
    qDebug() << __FUNCTION__ << QTime::currentTime().toString() << "\n";
}
