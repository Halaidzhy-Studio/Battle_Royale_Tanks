#include "multiplayermenu.h"
#include "ui_multiplayermenu.h"

MultiplayerMenu::MultiplayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerMenu)
{
    ui->setupUi(this);
}

MultiplayerMenu::~MultiplayerMenu()
{
    delete ui;
}
