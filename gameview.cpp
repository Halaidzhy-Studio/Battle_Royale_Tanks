#include "gameview.h"

void GameView::addObject(QGraphicsItem *item)
{
    gameScene_->addItem(item);
}
