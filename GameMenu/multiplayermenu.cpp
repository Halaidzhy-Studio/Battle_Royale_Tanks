#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include "multiplayermenu.h"

MultiplayerMenu::MultiplayerMenu(const std::shared_ptr<GameData>& gameData,
                                 const std::shared_ptr<Game>& game,
                                 QWidget *parent) :
    QWidget(parent), gameData_(gameData), game_(game)
{

    multiplayerMenuInfo_ = gameData_->getMultiplayerMenuInfo();

    setFixedSize(multiplayerMenuInfo_.width, multiplayerMenuInfo_.height);

    setStyleSheet(QString::fromStdString("background-color: " + multiplayerMenuInfo_.color + ";"));

    setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                    Qt::AlignCenter,
                                    size(),
                                    QApplication::desktop()->availableGeometry(this))
                );

    startMultiplayerGameBTN_ = new QPushButton("Start Game", this);
    startMultiplayerGameBTN_->setGeometry(width()/2, width()/multiplayerMenuInfo_.btn_padding,
                                          multiplayerMenuInfo_.start_btn_w, height()/multiplayerMenuInfo_.start_btn_h_k);

    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->setGeometry(width()/multiplayerMenuInfo_.btn_padding, width()/multiplayerMenuInfo_.btn_padding,
                                      multiplayerMenuInfo_.back_btn_w, height()/multiplayerMenuInfo_.back_btn_h_k);

    choseTankLabel_ = new QLabel("Chose a Tank", this);
    choseTankLabel_->setGeometry(width()/2 - multiplayerMenuInfo_.txt_label_w/2,
                                 height()/multiplayerMenuInfo_.txt_label_h_k + width()/multiplayerMenuInfo_.btn_padding,
                                 multiplayerMenuInfo_.txt_label_w, height()/multiplayerMenuInfo_.txt_label_h_k);

    prevTankBTN_ = new QPushButton("Previous", this);
    prevTankBTN_->setGeometry(width()/multiplayerMenuInfo_.btn_padding, height()/2, multiplayerMenuInfo_.prevt_btn_w,
                              height()/multiplayerMenuInfo_.prevt_btn_h_k);

    nextTankBTN_ = new QPushButton("Next", this);
    nextTankBTN_->setGeometry(width() - width()/multiplayerMenuInfo_.btn_padding - multiplayerMenuInfo_.nextt_btn_w,
                              height()/2,
                              multiplayerMenuInfo_.nextt_btn_w,
                              height()/multiplayerMenuInfo_.nextt_btn_h_k);

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
}

void MultiplayerMenu::previousTank()
{
}

void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
}
