#include "qtgraphicsitemadapter.h"

QtGraphicsItemAdapter::QtGraphicsItemAdapter(const std::shared_ptr<Graphics> & graphics) :
    graphics_(graphics)
{
    graphics_->addItem(this);
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
    rectF_.setX(x);
    rectF_.setY(yp);
    rectF_.setWidth(x);
    rectF_.setHeight(y);
}

void QtGraphicsItemAdapter::setRect(int w, int h)
{
    // -w/2, -h/2 центр координат предмета, совпадает с центром предмета
    rectF_.setX(-w/2);
    rectF_.setY(-h/2);
    rectF_.setWidth(w);
    rectF_.setHeight(h);
}

void QtGraphicsItemAdapter::setControlable()
{
    graphics_->setControlable(this);
}
