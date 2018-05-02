#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include "multiplayermenu.h"
#include "utils/constants.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent), gameInstance_(nullptr)
{


    setStyleSheet("background-color: white;");

    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height()*MENU_WINDOW_REDUCTION_FACTOR);

    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignCenter,
                    size(),
                    QApplication::desktop()->availableGeometry(this)));

    startMultiplayerGameBTN_ = new QPushButton("Start Game", this);
    startMultiplayerGameBTN_->setGeometry(width()/2, width()/100, 200, height()/15);

    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->setGeometry(width()/100, width()/100, 100, height()/15);

    choseTankLabel_ = new QLabel("Chose a Tank", this);
    choseTankLabel_->setGeometry(width()/2 - 100, height()/15 + 20, 200, height()/15);

    prevTankBTN_ = new QPushButton("Previous", this);
    prevTankBTN_->setGeometry(width()/100, height()/2, 100, height()/15);

    nextTankBTN_ = new QPushButton("Next", this);
    nextTankBTN_->setGeometry(width() - width()/100 - 100, height()/2, 100, height()/15);

    // Need to back to game menu
    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &MultiplayerMenu::backToMainWindow);
    connect(startMultiplayerGameBTN_, &QPushButton::released, this,
            &MultiplayerMenu::startMultiplayerGame);
    connect(prevTankBTN_, &QPushButton::released, this, &MultiplayerMenu::previousTank);
    connect(nextTankBTN_, &QPushButton::released, this, &MultiplayerMenu::nextTank);


}

void MultiplayerMenu::onShow(){
    show();
}

void MultiplayerMenu::startMultiplayerGame()
{

}

void MultiplayerMenu::nextTank()
{
   // currentTankTypeNum_ = (currentTankTypeNum_ + 1) % tankTypeList_.size();
   // chosenTankType_ = tankTypeList_[currentTankTypeNum_];
}

void MultiplayerMenu::previousTank()
{
   // currentTankTypeNum_ = (currentTankTypeNum_ - 1 + tankTypeList_.size()) % tankTypeList_.size();
   // chosenTankType_ = tankTypeList_[currentTankTypeNum_];
}

void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
}
