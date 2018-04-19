#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>
#include "singleplayermenu.h"
#include "utils/constants.h"

SingleplayerMenu::SingleplayerMenu(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_DeleteOnClose);
}

SingleplayerMenu::~SingleplayerMenu()
{

}


void SingleplayerMenu::initWindow()
{
    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height() * MENU_WINDOW_REDUCTION_FACTOR);

    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignCenter,
                    size(),
                    QApplication::desktop()->availableGeometry(this)));

    setStyleSheet("background-color: white;");

    startGameBTN_ = new QPushButton("Start", this);

    startGameBTN_->resize(100, 100);
    startGameBTN_->setGeometry(QStyle::alignedRect(
                                   Qt::RightToLeft,
                                   Qt::AlignBottom,
                                   startGameBTN_->size(),
                                   this->rect()));

    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->resize(100, 100);


    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &SingleplayerMenu::backToMainWindow);

    connect(startGameBTN_, &QPushButton::released, this,
            &SingleplayerMenu::startGame);


}

void SingleplayerMenu::backToMainWindow()
{
    this->close();
    emit mainWindow();
}

void SingleplayerMenu::startGame(){
    
}
