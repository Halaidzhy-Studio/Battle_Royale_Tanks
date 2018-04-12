#include <QTime>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsItem>
#include <GameObjects/tankgun.h>

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
    resize(QApplication::desktop()->width(),
           QApplication::desktop()->height());

    playScene_ = new QGraphicsScene(this);
    playScene_->setSceneRect(0, 0,
                             QApplication::desktop()->width(),
                             QApplication::desktop()->height());

    playView_ = new QGraphicsView(this);
    playView_->setScene(playScene_);
    playView_->resize(this->width(), this->height());
    playView_->setStyleSheet("background-color: white;");


    /*backToMultiplayerMenuBTN_ = new QPushButton("Back", this);
    backToMultiplayerMenuBTN_->resize(100, 100);

    connect(backToMultiplayerMenuBTN_, &QPushButton::released, this, &Multiplayer::onBackToMultiplayerMenu);
*/
    showFullScreen();
}

void Multiplayer::onBackToMultiplayerMenu(){
    close();
    emit multiplayerMenu();
}

void Multiplayer::startGame()
{

    player_ = new Tank(Tank::TankType::Simple);
   // TankGun* tankGun = new TankGun();
  //  tankGun->setParentItem(player_);
    player_->setFlag(QGraphicsItem::ItemIsFocusable);
    player_->setFocus();

    playScene_->addItem(player_);

    playSceneTimer_ = new QTimer();
    connect(playSceneTimer_, &QTimer::timeout, player_, &Tank::timerKeyEvent);

    playSceneTimer_->start(1000/30);

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
