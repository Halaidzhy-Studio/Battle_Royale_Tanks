#include <QDebug>
#include "roomlistelement.h"
#include "multiplayermenu.h"
RoomListElement::RoomListElement(QWidget *parent, GameRoom *gameRoom) : QWidget(parent),
    gameRoom_(gameRoom)
{



    setFixedSize(parent->width(), 50);

    connectToRoomBTN_ = new QPushButton(gameRoom->roomName(), this);
    connectToRoomBTN_->resize(width(), height());


    connect(connectToRoomBTN_, &QPushButton::clicked, this, &RoomListElement::connectToRoom);
    //connect(connectToRoomBTN_, &QPushButton::released, this->parent()->parent(), &MultiplayerMenu::closeMenu);
}

RoomListElement::~RoomListElement()
{
    qDebug() << __FUNCTION__ << "\n";

    delete gameRoom_;
}

void RoomListElement::connectToRoom()
{
    // Make connection
    qDebug() << "Connect to room " << gameRoom_->roomName();

    emit doCloseMenu();

    //gameScene_->renderGame();
    //gameScene_->startGame();

}

GameInstance* RoomListElement::gameScene() const
{
    return gameScene_;
}

void RoomListElement::setGameScene(GameInstance* gameScene)
{
    gameScene_ = gameScene;
}

GameRoom *RoomListElement::gameRoom() const
{
    return gameRoom_;
}

void RoomListElement::setGameRoom(GameRoom *gameRoom)
{
    gameRoom_ = gameRoom;
}
