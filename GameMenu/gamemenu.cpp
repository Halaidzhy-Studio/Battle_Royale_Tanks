#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>
#include "gamemenu.h"
#include "utils/logger.h"

GameMenu::GameMenu(const std::shared_ptr<GameData>& gameData,
                   const std::shared_ptr<Game>& game,
                   const std::shared_ptr<Logger>& logger,
                   QWidget *parent) : QWidget(parent), gameData_(gameData),
                   game_(game), logger_(logger)
{

    menuWindowInfo_ = gameData_->getMenuWindowInfo();

    std::string backgroundColor = menuWindowInfo_.color;

    setStyleSheet(QString::fromStdString("background-color: " + backgroundColor + ";"));
    setFixedSize(menuWindowInfo_.width, menuWindowInfo_.height);

    // Center widget on screen
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                    Qt::AlignCenter,
                                    size(),
                                    QApplication::desktop()->availableGeometry(this))
                );

    spWindow_ = new SingleplayerMenu(gameData_, game_);

    // connected to slot, which run the main window on the button in the Singleplayer Window
    connect(spWindow_, &SingleplayerMenu::mainWindow, this, &GameMenu::show);

    mpWindow_ = new MultiplayerMenu(gameData_, game_);

    // connected to slot, which run the main window on the button in the Multiplayer Window
    connect(mpWindow_, &MultiplayerMenu::mainWindow, this, &GameMenu::show);

    singleplayerBTN_ = new QPushButton("Singleplayer", this);

    // size.width()/2 - size().width()/menuWindowInfo_.btn_w_k/2 - set Button to center of MainMenu
    singleplayerBTN_->setGeometry(size().width()/2 - size().width()/menuWindowInfo_.btn_w_k/2,
                                 1 * size().height()/menuWindowInfo_.btn_part_size,
                                 size().width()/menuWindowInfo_.btn_w_k, size().height()/menuWindowInfo_.btn_h_k);

    multiplayerBTN_ = new QPushButton("Multiplayer", this);

    // size.width()/2 - size().width()/menuWindowInfo_.btn_w_k/2 - set Button to center of MainMenu
    multiplayerBTN_->setGeometry(size().width()/2 - width()/menuWindowInfo_.btn_w_k/2,
                                 2 * size().height()/menuWindowInfo_.btn_part_size,
                                 size().width()/menuWindowInfo_.btn_w_k, size().height()/menuWindowInfo_.btn_h_k);

    exitBTN_ = new QPushButton("Exit", this);

    // size.width()/2 - size().width()/menuWindowInfo_.btn_w_k/2 - set Button to center of MainMenu
    exitBTN_->setGeometry(size().width()/2 - width()/menuWindowInfo_.btn_w_k/2,
                                 3 * size().height()/menuWindowInfo_.btn_part_size,
                                 size().width()/menuWindowInfo_.btn_w_k, size().height()/menuWindowInfo_.btn_h_k);

    // SingleplayerMenu is opened by singlePlayerBTN_
    connect(singleplayerBTN_, &QPushButton::released, this, &GameMenu::showSingleplayerMenu);

    // MultiPlayerMenu is opened by multiplayerBTN_
    connect(multiplayerBTN_, &QPushButton::released, this, &GameMenu::showMultiplayerMenu);

    // Window is closed by exitBTN_
    connect(exitBTN_, &QPushButton::released, this, &QApplication::quit);


}

void GameMenu::showMultiplayerMenu(){
    mpWindow_->show();
    this->close();
}

void GameMenu::showSingleplayerMenu()
{
    spWindow_->show();
    this->close();
}

