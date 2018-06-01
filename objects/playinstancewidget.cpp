#include "playinstancewidget.h"

PlayInstanceWidget::PlayInstanceWidget()
{

}

PlayInstanceWidget::PlayInstanceWidget(const std::shared_ptr<GameData> & gameData) : gameData_(gameData)
{
    gameWindowInfo_ = gameData_->getGameWindowInfo();
    setFixedSize(800, 800);
}
