#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>
#include "gamemenu.h"

GameMenu::GameMenu(QWidget *parent) : QWidget(parent)
{

    setStyleSheet("background-color: white;");
    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height()*0.90f);

    // Center widget on screen
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,
                                    Qt::AlignCenter,
                                    size(),
                                    QApplication::desktop()->availableGeometry(this))
                );

    spWindow_ = new SingleplayerMenu();

    // connected to slot, which run the main window on the button in the Singleplayer Window
    connect(spWindow_, &SingleplayerMenu::mainWindow, this, &GameMenu::show);

    mpWindow_ = new MultiplayerMenu();

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

