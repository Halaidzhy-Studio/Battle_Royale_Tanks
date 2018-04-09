#include "playwidget.h"
#include "tank.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "ui_playwidget.h"

PlayWidget::PlayWidget(QWidget* parent):QWidget(parent), ui(new Ui::PlayWidget){
    ui->setupUi(this);
    this->resize(1280, 720);

    playScene_ = new QGraphicsScene();
    playScene_->setSceneRect(0, 0, 800, 800 );

    Tank* tank = new Tank();
    tank->setFlag(QGraphicsItem::ItemIsFocusable);
    tank->setFocus();
    playScene_->addItem(tank);

    this->ui->graphicsView->setScene(playScene_);
    this->ui->graphicsView->showFullScreen();
    this->ui->graphicsView->resize(this->width(), this->height());

    gameTimer = new QTimer();

    connect(gameTimer, &QTimer::timeout, tank, &Tank::timerKeyEvent);
    gameTimer->start(1000/50);


}

PlayWidget::~PlayWidget()
{
    delete ui;
}
