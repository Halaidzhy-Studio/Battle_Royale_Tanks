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

    roomsList_ = new QListWidget(this);
    roomsList_->setGeometry(this->width()/100, 2*height()/15, width() - width()/50, height());

    // Make list of rooms, instead 1 count of rooms


    for (int i = 0; i < 1; i++){
        createRoomsListElement(roomsList_);
    }

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &MultiplayerMenu::backToMainWindow);

}

void MultiplayerMenu::createRoomsListElement(QListWidget* roomsList){
    RoomListElement* roomElement = new RoomListElement(roomsList);
    QListWidgetItem* item = new QListWidgetItem(roomsList);

    roomsList->setItemWidget(item, roomElement);

}
void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
    delete ui;
}
