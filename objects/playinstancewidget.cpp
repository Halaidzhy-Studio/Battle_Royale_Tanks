#include "playinstancewidget.h"
#include <QDesktopWidget>
#include <QApplication>

PlayInstanceWidget::PlayInstanceWidget()
{

}

PlayInstanceWidget::PlayInstanceWidget(const std::shared_ptr<GameData> &gameData,
                                       const std::shared_ptr<Graphics> &graphics) :
    gameData_(gameData), graphics_(graphics)
{
    gameWindowInfo_ = gameData_->getGameWindowInfo();

    if (gameWindowInfo_.is_full_screen){
        setFixedSize(QApplication::desktop()->width(), QApplication::desktop()->height());
    }else {
        setFixedSize(gameWindowInfo_.width, gameWindowInfo_.height);
    }
    graphics->setViewParent(this);
    initInterface();
}

void PlayInstanceWidget::initInterface()
{

    exitBTN_ = new QPushButton("Exit", this);
    exitBTN_->setGeometry(size().width() - size().width()/gameWindowInfo_.btn_padding - gameWindowInfo_.back_btn_width,
                          size().height()/gameWindowInfo_.btn_padding,
                          gameWindowInfo_.back_btn_width, gameWindowInfo_.back_btn_height);
    graphics_->addWidget(exitBTN_);

    connect(exitBTN_, &QPushButton::released, this, &PlayInstanceWidget::exit);
}

void PlayInstanceWidget::exit()
{
    this->close();
    emit exitSignal();
}
