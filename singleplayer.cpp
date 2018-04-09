#include <QPushButton>

#include "singleplayer.h"
#include "ui_singleplayer.h"

Singleplayer::Singleplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Singleplayer)
{
    ui->setupUi(this);


    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->resize(100, 100);

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &Singleplayer::backToMainWindow);
}

void Singleplayer::backToMainWindow(){
    this->close();
    emit mainWindow();
}

Singleplayer::~Singleplayer()
{
    delete ui;
}
