#include "gamewidget.h"

PlaygroundWidget::PlaygroundWidget(const std::shared_ptr<GameData>& gameData,
                       const std::shared_ptr<Logger>& logger,
                       QWidget *parent) : QWidget(parent), gameData_(gameData), logger_(logger)
{
    gameWindowInfo_ = gameData_->getGameWindowInfo();
}

PlaygroundWidget::~PlaygroundWidget()
{

}

void PlaygroundWidget::initInterface()
{
    backToMenuBTN_ = new QPushButton("Back", this);
    backToMenuBTN_->setGeometry(width() - width()/gameWindowInfo_.btn_padding - gameWindowInfo_.back_btn_width,
                                width()/gameWindowInfo_.btn_padding,
                                gameWindowInfo_.back_btn_width,
                                gameWindowInfo_.back_btn_height);

    connect(backToMenuBTN_, &QPushButton::released,this, &PlaygroundWidget::backToMenu);

    if (gameWindowInfo_.isFullScrean){
        showFullScreen();
    } else {
        show();
        setFixedSize(gameWindowInfo_.width, gameWindowInfo_.height);
    }
}

void PlaygroundWidget::backToMenu()
{
    this->close();
    emit backToMenuSignal();
}
