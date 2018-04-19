#include <QApplication>
#include <QDesktopWidget>

#include "roomlistelement.h"
#include <QDebug>
#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"
#include "utils/constants.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerMenu), gameInstance_(nullptr)
{
    ui->setupUi(this);

    // Debug
    roomsCount = 2;

    setStyleSheet("background-color: white;");

    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height()*MENU_WINDOW_REDUCTION_FACTOR);

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

    getRooms();
    initMenu();

    // Need to back to game menu
    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &MultiplayerMenu::backToMainWindow);


}

void MultiplayerMenu::initMenu(){
    if (gameInstance_ != nullptr)
        delete gameInstance_;

    gameInstance_ = new GameInstance();

    formRoomsList(roomsListWidget_);
}

void MultiplayerMenu::getRooms(){

    while (roomsCount--){
        QString str =  "Room " + QString::number(roomsCount);
        roomsList_.push_back(new GameRoom(str.toStdString(),static_cast<short int>(32), static_cast<short int>(2)));
    }
}

// Form Rooms List Widget
void MultiplayerMenu::formRoomsList(QListWidget* roomsListWidget){

    //
    qDebug() << roomsListWidget->count() << "\n";

    if (roomsListWidget->count() < roomsList_.size())
        for (const auto& room: roomsList_){
            createRoomsListElement(roomsListWidget, room);
        }
}

void MultiplayerMenu::createRoomsListElement(QListWidget *roomsListWidget, GameRoom* gameRoom){
    RoomListElement* roomElement = new RoomListElement(roomsListWidget, gameRoom, gameInstance_);

    QListWidgetItem* item = new QListWidgetItem(roomsListWidget);
    item->setSizeHint(QSize(roomsListWidget->width(), 50));
    roomsListWidget->setItemWidget(item, roomElement);

    // To be able close menu, after start Game
    connect(roomElement, &RoomListElement::doCloseMenu, this, &MultiplayerMenu::close);

    //connect(gameScene_, &Multiplayer::multiplayerMenu, this, &MultiplayerMenu::onShow);
}

void MultiplayerMenu::onShow(){
    initMenu();
    show();
}

void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
    delete ui;
}
