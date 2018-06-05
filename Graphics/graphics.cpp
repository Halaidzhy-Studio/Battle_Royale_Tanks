#include "graphics.h"
#include <QGraphicsItem>

Graphics::Graphics() : graphicsScene_(new QGraphicsScene()),
                       graphicsView_(new QGraphicsView())
{
    graphicsScene_->setSceneRect(-150, -150, 300, 300);
    graphicsView_->setScene(graphicsScene_);
}

Graphics::~Graphics()
{
    // Так как временем жизни объектов управляет родительский widget
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

void Graphics::setViewParent(QWidget *parent)
{
    graphicsView_->setParent(parent);
    graphicsView_->setFixedSize(parent->size());
}

void Graphics::addWidget(QWidget *widget)
{
    graphicsScene_->addWidget(widget);
}
