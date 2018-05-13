#include "gamewidget.h"

GameWidget::GameWidget(const std::shared_ptr<GameData>& gameData,
                       const std::shared_ptr<Logger>& logger,
                       QWidget *parent) : QWidget(parent), gameData_(gameData), logger_(logger)
{
    gameWindowInfo_ = gameData_->getGameWindowInfo();
}

GameWidget::~GameWidget()
{

}

void GameWidget::initInterface()
{
    backToMenuBTN_ = new QPushButton("Back", this);
    backToMenuBTN_->setGeometry(width() - width()/gameWindowInfo_.btn_padding - gameWindowInfo_.back_btn_width,
                                width()/gameWindowInfo_.btn_padding,
                                gameWindowInfo_.back_btn_width,
                                gameWindowInfo_.back_btn_height);

    connect(backToMenuBTN_, &QPushButton::released,this, &GameWidget::backToMenu);

    if (gameWindowInfo_.isFullScrean){
        showFullScreen();
    } else {
        show();
        setFixedSize(gameWindowInfo_.width, gameWindowInfo_.height);
    }
}

void GameWidget::backToMenu()
{
    this->close();
    emit backToMenuSignal();
}
