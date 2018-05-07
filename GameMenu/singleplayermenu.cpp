#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>
#include "singleplayermenu.h"


SingleplayerMenu::SingleplayerMenu(const std::shared_ptr<GameData>& gameData, QWidget *parent) : QWidget(parent),
    gameData_(gameData)
{

    singleplayernMenuInfo_ = gameData_->getSingleplayerMenuInfo();
    setFixedSize(singleplayernMenuInfo_.width, singleplayernMenuInfo_.height);

    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignCenter,
                    size(),
                    QApplication::desktop()->availableGeometry(this)));

    std::string backgroundColor = singleplayernMenuInfo_.color;
    setStyleSheet(QString::fromStdString("background-color: " + backgroundColor  + ";" ));

    startGameBTN_ = new QPushButton("Start", this);

    startGameBTN_->resize(width()/singleplayernMenuInfo_.btn_w_k, height()/singleplayernMenuInfo_.btn_h_k);

    startGameBTN_->setGeometry(QStyle::alignedRect(
                                   Qt::RightToLeft,
                                   Qt::AlignBottom,
                                   startGameBTN_->size(),
                                   this->rect()));


    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->resize(width()/singleplayernMenuInfo_.btn_w_k, height()/singleplayernMenuInfo_.btn_h_k);

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &SingleplayerMenu::backToMainWindow);

}

SingleplayerMenu::~SingleplayerMenu()
{

}


void SingleplayerMenu::backToMainWindow()
{
    this->close();
    emit mainWindow();
}

void SingleplayerMenu::startGame(){

}
