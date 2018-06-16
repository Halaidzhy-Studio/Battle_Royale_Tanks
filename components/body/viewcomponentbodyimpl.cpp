#include "viewcomponentbodyimpl.h"

ViewComponentBodyImpl::ViewComponentBodyImpl()
{
}

QRectF ViewComponentBodyImpl::boundingRect() const
{
    return QRectF(-rectInfo_.w/2, -rectInfo_.h/2, rectInfo_.w, rectInfo_.h);
}

void ViewComponentBodyImpl::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->drawRect(boundingRect());
}

void ViewComponentBodyImpl::update(GameObject *gameObject)
{
    this->setPos(bodyInfo_->coord().toQt().x(), bodyInfo_->coord().toQt().y());
    this->setRotation(bodyInfo_->angle());
}
