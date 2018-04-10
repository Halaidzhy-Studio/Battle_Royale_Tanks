#include <QDebug>
#include "roomlistelement.h"

RoomListElement::RoomListElement(QWidget *parent) : QWidget(parent)
{

    setGeometry(width()/50, width()/50, width(), height()/15);
    setFixedSize(parent->width(), 50);

    connectToRoomBTN_ = new QPushButton("Room 1", this);
    connectToRoomBTN_->resize(width(), height());

    connect(connectToRoomBTN_, &QPushButton::released, this, [this]{ connectToRoom(1); });

}

void RoomListElement::connectToRoom(int roomNumber)
{
    // Make connection
    qDebug() << "Open room number " << roomNumber;
}
