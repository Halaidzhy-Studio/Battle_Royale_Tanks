#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>
#include "gamemenu.h"
#include "utils/logger.h"
#include "utils/constants.h"

GameMenu::GameMenu(int width, int height, const std::shared_ptr<libconfig::Config> config,
                   QWidget *parent) : QWidget(parent),
    menuWidth_(width), menuHeight_(height), config_(config)
{

    std::string backgroundColor = "white";
    try{
        backgroundColor = config_->lookup("windows.menu.background_color").c_str();
    }catch(const libconfig::SettingNotFoundException& e){
        Logger::instance().printLog("No 'windows.menu.background_color' setting in configuration file", Logger::loggerGame);
    }

    setStyleSheet(QString::fromStdString("background-color: " + backgroundColor + ";"));
    setFixedSize(menuWidth_, menuHeight_);

    // Center widget on screen
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                    Qt::AlignCenter,
                                    size(),
                                    QApplication::desktop()->availableGeometry(this))
                );

    spWindow_ = new SingleplayerMenu();

    // connected to slot, which run the main window on the button in the Singleplayer Window
    connect(spWindow_, &SingleplayerMenu::mainWindow, this, &GameMenu::show);

    mpWindow_ = new MultiplayerMenu(menuWidth_, menuHeight_);

    // connected to slot, which run the main window on the button in the Multiplayer Window
    connect(mpWindow_, &MultiplayerMenu::mainWindow, this, &GameMenu::show);

    singleplayerBTN_ = new QPushButton("Singleplayer", this);

    // size.width()/2 - size().width()/6 - set Button to center of MainMenu
    singleplayerBTN_->setGeometry(size().width()/2 - size().width()/6,
                                 1 * size().height()/5,
                                 size().width()/3, size().height()/8);

    multiplayerBTN_ = new QPushButton("Multiplayer", this);

    // size.width()/2 - size().width()/6 - set Button to center of MainMenu
    multiplayerBTN_->setGeometry(size().width()/2 - size().width()/6,
                                 2 * size().height()/5,
                                 size().width()/3, size().height()/8);

    exitBTN_ = new QPushButton("Exit", this);

    // size.width()/2 - size().width()/6 - set Button to center of MainMenu
    exitBTN_->setGeometry(size().width()/2 - size().width()/6,
                                 3 * size().height()/5,
                                 size().width()/3, size().height()/8);

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
    spWindow_ ->initWindow();
    spWindow_->show();
    this->close();
}

