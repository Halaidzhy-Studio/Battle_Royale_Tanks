#include "qtgraphicsitemadapter.h"
#include <engine.h>

QtGraphicsItemAdapter::QtGraphicsItemAdapter(const std::shared_ptr<Graphics> & graphics,
                                             const std::shared_ptr<Logger>& logger) :
    graphics_(graphics), logger_(logger), keys_(0), isScalableTexture_(true), opacity_(1)
{
    graphics_->addItem(this);
}

QRectF QtGraphicsItemAdapter::boundingRect() const
{
    return rectF_;
}

void QtGraphicsItemAdapter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF res(0, 0,pixmap.width(), pixmap.height());
    painter->setOpacity(opacity_);
    painter->drawPixmap(boundingRect(), pixmap, res);
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

void QtGraphicsItemAdapter::setTexture(const std::string &path)
{
    pixmap.load(path.c_str());
}

void QtGraphicsItemAdapter::setRect(int w, int h)
{
    setRect(-w/2, -h/2, w, h);
}

void QtGraphicsItemAdapter::setRect(int x, int y, int w, int h)
{
    prepareGeometryChange();
    rectF_.setX(x);
    rectF_.setY(y);
    rectF_.setWidth(w);
    rectF_.setHeight(h);

    if (isScalableTexture_)
        pixmap = pixmap.scaled(w, h);
}

void QtGraphicsItemAdapter::setControlable()
{
    graphics_->setControlable(this);
}


void QtGraphicsItemAdapter::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ |= static_cast<int>(Engine::Keys::KEY_W); break;
    case Qt::Key_S: keys_ |= static_cast<int>(Engine::Keys::KEY_S); break;
    case Qt::Key_D: keys_ |= static_cast<int>(Engine::Keys::KEY_D); break;
    case Qt::Key_A: keys_ |= static_cast<int>(Engine::Keys::KEY_A); break;
    case Qt::Key_Left: keys_ |= static_cast<int>(Engine::Keys::KEY_LEFT); break;
    case Qt::Key_Right: keys_ |= static_cast<int>(Engine::Keys::KEY_RIGHT); break;
    case Qt::Key_Space: keys_ |= static_cast<int>(Engine::Keys::KEY_SPACE); break;
    default:
        break;
    }
}

void QtGraphicsItemAdapter::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ &= ~static_cast<int>(Engine::Keys::KEY_W); break;
    case Qt::Key_S: keys_ &= ~static_cast<int>(Engine::Keys::KEY_S); break;
    case Qt::Key_D: keys_ &= ~static_cast<int>(Engine::Keys::KEY_D); break;
    case Qt::Key_A: keys_ &= ~static_cast<int>(Engine::Keys::KEY_A); break;
    case Qt::Key_Left: keys_ &= ~static_cast<int>(Engine::Keys::KEY_LEFT); break;
    case Qt::Key_Right: keys_ &= ~static_cast<int>(Engine::Keys::KEY_RIGHT); break;
    case Qt::Key_Space: keys_ &= ~static_cast<int>(Engine::Keys::KEY_SPACE); break;
    default:
        break;
    }
}

int QtGraphicsItemAdapter::getActiveKeys()
{
    return keys_;
}

void QtGraphicsItemAdapter::setParent(GraphicsItem *graphicsItem)
{
    QtGraphicsItemAdapter* qtItem
            = dynamic_cast<QtGraphicsItemAdapter*>(graphicsItem);
    if (qtItem)
        this->setParentItem(qtItem);
    else {
        logger_->printLog("Bad cast GraphicsItem to QtGraphicsItemAdapter", "[QtGraphicsItemAdapter]");
    }
}

void QtGraphicsItemAdapter::setIsScalableTexture(bool isScalableTexture)
{
    isScalableTexture_ = isScalableTexture;
}

void QtGraphicsItemAdapter::setOpacity(double opacity)
{
    opacity_ = opacity;
}

void QtGraphicsItemAdapter::close()
{
    hide();
}
