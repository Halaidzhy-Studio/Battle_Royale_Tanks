#include <QPushButton>
#include <QDesktopWidget>
#include "singleplayer.h"
#include "ui_singleplayer.h"

Singleplayer::Singleplayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Singleplayer)
{
    ui->setupUi(this);
    resize(QApplication::desktop()->width(), QApplication::desktop()->height());

    playScene_ = new QGraphicsScene(-300, -300, width(), height(), this);

    getTanks(tanks_);
    addTanksToScene(tanks_, playScene_);

    // Able to control 1 tank
    tanks_[0]->setFlag(QGraphicsItem::ItemIsFocusable);
    tanks_[0]->setFocus();
    tanks_[0]->setX(50);

    playView_ = new QGraphicsView(playScene_, this);
    playView_->resize(width(), height());

    backToMainWindowBTN_ = new QPushButton("Back", this);
    backToMainWindowBTN_->resize(100, 100);

    gameTimer_ = new QTimer();

    connect(gameTimer_, &QTimer::timeout, tanks_[0], &Tank::timerKeyEvent);
    gameTimer_->start(1000/25);

    connect(backToMainWindowBTN_, &QPushButton::released, this,
            &Singleplayer::backToMainWindow);
}

void Singleplayer::backToMainWindow(){
    this->close();
    emit mainWindow();
}

void Singleplayer::addTanksToScene(QVector<Tank*>& tanks, QGraphicsScene* playScene){
    for (int i = 0; i < tanks.size(); ++i){
        playScene->addItem(tanks[i]);
    }
}

void Singleplayer::getTanks(QVector<Tank*>& tanks){
    // Get Tanks
    int tanksCount = 2;
    for (int i = 0; i < tanksCount; ++i){
        tanks.push_back(new Tank(Tank::TankType::Simple));
    }

}

Singleplayer::~Singleplayer()
{
    delete ui;
}
