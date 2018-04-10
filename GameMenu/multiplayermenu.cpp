#include <QApplication>
#include <QDesktopWidget>
#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerMenu)
{
    ui->setupUi(this);
    setFixedSize(QApplication::desktop()->width()/2,
                 QApplication::desktop()->height());

    backToMainWindowBTN_ = new QPushButton("Back", this);

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &MultiplayerMenu::backToMainWindow);

}

void MultiplayerMenu::backToMainWindow(){
    this->close();
    emit mainWindow();
}

MultiplayerMenu::~MultiplayerMenu()
{
    delete ui;
}
