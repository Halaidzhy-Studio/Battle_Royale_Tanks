#include <QDesktopWidget>
#include <QApplication>
#include <QStyle>
#include "singleplayermenu.h"

SingleplayerMenu::SingleplayerMenu(const std::shared_ptr<GameData>& gameData,
                                   const std::shared_ptr<Logger>& logger,
                                   QWidget *parent) : QWidget(parent),
    gameData_(gameData), logger_(logger)
{

    singleplayernMenuInfo_ = gameData_->getSingleplayerMenuInfo();

    // Пока что есть только один тип танков.
    tankType_ = TankTypes::DEFAULT;
    playInstance_ = std::make_unique<PlayInstance>(gameData_, logger_);

    connect(playInstance_.get(), &PlayInstance::stopSignal, this, &SingleplayerMenu::stopGame);
    initInterface();
}

SingleplayerMenu::~SingleplayerMenu()
{
}


void SingleplayerMenu::backToMainWindow()
{
    this->close();
    emit mainWindow();
}

void SingleplayerMenu::startGame()
{
    close();
    playInstance_->setPlayerTankType(tankType_);
    playInstance_->start();
}

void SingleplayerMenu::initInterface()
{
    setFixedSize(singleplayernMenuInfo_.width, singleplayernMenuInfo_.height);

    setGeometry(QStyle::alignedRect(
                    Qt::RightToLeft,
                    Qt::AlignCenter,
                    size(),
                    QApplication::desktop()->availableGeometry(this)));

    std::string backgroundColor = singleplayernMenuInfo_.color;
    setStyleSheet(QString::fromStdString("background-color: " + backgroundColor  + ";" ));

    startGameBTN_ = new QPushButton("Start", this);

    connect(startGameBTN_, &QPushButton::released, this, &SingleplayerMenu::startGame);

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

void SingleplayerMenu::stopGame()
{
    // Удаляем предыдущую сессию.
    playInstance_.reset(new PlayInstance(gameData_, logger_));
    connect(playInstance_.get(), &PlayInstance::stopSignal, this, &SingleplayerMenu::stopGame);

    show();
}
