#include "qtgraphicsitemadapter.h"

QtGraphicsItemAdapter::QtGraphicsItemAdapter(const std::shared_ptr<Graphics> & graphics) :
    graphics_(graphics), keys_(0)
{
    graphics_->addItem(this);
}

QRectF QtGraphicsItemAdapter::boundingRect() const
{
    return rectF_;
}

void QtGraphicsItemAdapter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Test need to delete later
    painter->setPen(Qt::black);
    painter->drawRect(rectF_);
}

void QtGraphicsItemAdapter::setPos(Coordinate coord)
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
    rectF_ = QRectF(-w/2, -h/2, w, h);
}

void QtGraphicsItemAdapter::setControlable()
{
    graphics_->setControlable(this);
}


void QtGraphicsItemAdapter::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ |= KEY_W; break;
    case Qt::Key_S: keys_ |= KEY_S; break;
    case Qt::Key_D: keys_ |= KEY_D; break;
    case Qt::Key_A: keys_ |= KEY_A; break;
    default:
        break;
    }
}

void QtGraphicsItemAdapter::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ &= ~KEY_W; break;
    case Qt::Key_S: keys_ &= ~KEY_S; break;
    case Qt::Key_D: keys_ &= ~KEY_D; break;
    case Qt::Key_A: keys_ &= ~KEY_A; break;
    default:
        break;
    }
}

int QtGraphicsItemAdapter::getActiveKeys()
{
    return keys_;
}
