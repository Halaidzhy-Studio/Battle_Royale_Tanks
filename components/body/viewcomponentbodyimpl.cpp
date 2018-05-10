#include "viewcomponentbodyimpl.h"

ViewComponentBodyImpl::ViewComponentBodyImpl()
{

}


QRectF ViewComponentBodyImpl::boundingRect() const
{
    return QRectF(-rectInfo.w/2, -rectInfo.h/2, rectInfo.w, rectInfo.h);
}

void ViewComponentBodyImpl::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void ViewComponentBodyImpl::update(GameObject *gameObject)
{
    this->setPos(gameObject->getCoord().toQt().x(), gameObject->getCoord().toQt().y());
    this->setRotation(gameObject->getAngle().toQT());
}
