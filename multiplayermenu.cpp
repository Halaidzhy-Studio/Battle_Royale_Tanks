#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerMenu)
{
    ui->setupUi(this);

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
