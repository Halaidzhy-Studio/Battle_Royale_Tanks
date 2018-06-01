#include "qtgraphicsitemadapter.h"

QtGraphicsItemAdapter::QtGraphicsItemAdapter(const std::shared_ptr<Graphics> & graphics) :
    graphics_(graphics)
{

}

QRectF QtGraphicsItemAdapter::boundingRect() const
{
    return rectF_;
}

void QtGraphicsItemAdapter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->drawRect(rectF_);
}

void QtGraphicsItemAdapter::setPos(Coordinate& coord)
{
    QGraphicsItem::setPos(coord.toQt().x(), coord.toQt().y());
}

void QtGraphicsItemAdapter::setRotation(int rotation)
{
    QGraphicsItem::setRotation(rotation);
}

void QtGraphicsItemAdapter::isControlable(bool)
{

}

void QtGraphicsItemAdapter::setTexture(Texture)
{
}

void QtGraphicsItemAdapter::setRect(int xp, int yp, int x, int y)
{
    rectF_.setX(xp);
    rectF_.setY(yp);
    rectF_.setWidth(x);
    rectF_.setHeight(y);
}

void QtGraphicsItemAdapter::setControlable()
{
    graphics_->setControlable(this);
}
