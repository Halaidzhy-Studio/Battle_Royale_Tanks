#include "graphics.h"
#include <QGraphicsItem>

Graphics::Graphics() : graphicsScene_(std::make_unique<QGraphicsScene>())
{
}

void Graphics::setSceneRect(int xp, int yp, int x, int y)
{
    graphicsScene_->setSceneRect(xp, yp, x, y);
}


void Graphics::addItem(QGraphicsItem *item)
{
    graphicsScene_->addItem(item);
}

void Graphics::setControlable(QGraphicsItem *item)
{
    item->setFocus();
    item->setFlag(QGraphicsItem::ItemIsFocusable);
}
