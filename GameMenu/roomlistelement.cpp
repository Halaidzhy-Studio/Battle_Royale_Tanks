#include <QDebug>
#include "roomlistelement.h"
#include "multiplayermenu.h"
RoomListElement::RoomListElement(QWidget *parent) : QWidget(parent)
{

    setGeometry(width()/50, width()/50, width(), height()/15);
    setFixedSize(parent->width(), 50);

    connectToRoomBTN_ = new QPushButton("Room 1", this);
    connectToRoomBTN_->resize(width(), height());


    connect(connectToRoomBTN_, &QPushButton::clicked, this, &RoomListElement::connectToRoom);
    //connect(connectToRoomBTN_, &QPushButton::released, this->parent()->parent(), &MultiplayerMenu::closeMenu);
}

RoomListElement::~RoomListElement()
{
    qDebug() << __FUNCTION__ << "\n";

    delete gameRoom_;
    delete roomName_;
    delete connectToRoomBTN_;
}

void RoomListElement::connectToRoom()
{
    // Make connection
    qDebug() << "Connect to room " << gameRoom_->roomName();

    //gameScene_ = std::make_shared<Multiplayer>(nullptr, gameRoom_);
    emit doCloseMenu();

    gameScene_->renderGame();
    gameScene_->startGame();

}

Multiplayer *RoomListElement::gameScene() const
{
    return gameScene_;
}

void RoomListElement::setGameScene(Multiplayer *gameScene)
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
