#include "qtgraphicsitemadapter.h"

QtGraphicsItemAdapter::QtGraphicsItemAdapter(const std::shared_ptr<Graphics> & graphics) :
    graphics_(graphics), keys_(0)
{
    graphics_->addItem(this);
    // pixmap.load(":Resources/images/Tank.png");
}

QRectF QtGraphicsItemAdapter::boundingRect() const
{
    return rectF_;
}

void QtGraphicsItemAdapter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF res(0, 0,pixmap.height(), pixmap.width());
    painter->drawPixmap(rectF_, pixmap, res);

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

void QtGraphicsItemAdapter::setTexture(Texture texture)
{
    pixmap.load(texture.pathTo.c_str());
}

void QtGraphicsItemAdapter::setRect(int w, int h)
{
    prepareGeometryChange();
    rectF_.setX(-w/2);
    rectF_.setY(-h/2);
    rectF_.setWidth(w);
    rectF_.setHeight(h);

    //pixmap = pixmap.scaled(w, h);
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
