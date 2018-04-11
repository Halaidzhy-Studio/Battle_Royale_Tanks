#include <QApplication>
#include <QDesktopWidget>

#include "roomlistelement.h"
#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerMenu)
{
    ui->setupUi(this);

    setStyleSheet("background-color: white;");

    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height());

    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignCenter,
                    size(),
                    QApplication::desktop()->availableGeometry(this)));

    multiplayerMenuTitle_ = new QLabel("Rooms", this);
    multiplayerMenuTitle_->setGeometry(width()/2, width()/100, 100, height()/15);

    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_ ->setGeometry(width()/100, width()/100, 100, height()/15);


    roomsListWidget_ = new QListWidget(this);
    roomsListWidget_->setGeometry(this->width()/100, 2*height()/15, width() - width()/50, height());

    // Download rooms to QVector<GameRoom>
    getRooms();

    formRoomsList(roomsListWidget_);

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &MultiplayerMenu::backToMainWindow);

}

void MultiplayerMenu::getRooms(){
    // Download rooms to QVector<GameRoom>
    qint16 roomsCount = 1;

    while (roomsCount--){
        roomsList_.push_back(new GameRoom());
    }
}

// Form Rooms List Widget
void MultiplayerMenu::formRoomsList(QListWidget* roomsListWidget){

    for (qint16 i = 0; i < roomsList_.size(); ++i){
        createRoomsListElement(roomsListWidget, roomsList_[i]);
    }
}

void MultiplayerMenu::createRoomsListElement(QListWidget *roomsListWidget){
    RoomListElement* roomElement = new RoomListElement(roomsListWidget);
    QListWidgetItem* item = new QListWidgetItem(roomsListWidget);

    roomsListWidget->setItemWidget(item, roomElement);

}
void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
    delete ui;
}
