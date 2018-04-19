#include <QDebug>
#include "roomlistelement.h"
#include "multiplayermenu.h"
RoomListElement::RoomListElement(QWidget *parent, GameRoom *gameRoom, GameInstance * gameInstance) : QWidget(parent),
    gameRoom_(gameRoom), gameInstance_(gameInstance)
{

    setFixedSize(parent->width(), 50);

    connectToRoomBTN_ = new QPushButton(QString::fromStdString(gameRoom->roomName()), this);
    connectToRoomBTN_->resize(width(), height());


    connect(connectToRoomBTN_, &QPushButton::clicked, this, &RoomListElement::connectToRoom);
    //connect(connectToRoomBTN_, &QPushButton::released, this->parent()->parent(), &MultiplayerMenu::closeMenu);
}

RoomListElement::~RoomListElement()
{
    delete gameInstance_;
    delete gameRoom_;
}

void RoomListElement::connectToRoom()
{
    // Make connection
    //qDebug() << "Connect to room " << gameRoom_->roomName();

    emit doCloseMenu();

}

