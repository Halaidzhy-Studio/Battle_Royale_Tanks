#include <QPainter>
#include "tankgun.h"

TankGun::TankGun():  gunWidth_(0),
    gunHeight_(0)
{

}

TankGun::TankGun(quint16 width, quint16 height): gunWidth_(width), gunHeight_(height)
{
}

TankGun::~TankGun()
{

}

QRectF TankGun::boundingRect() const
{
    return QRectF(0,0, gunWidth_, gunHeight_);
}

void TankGun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawRect(boundingRect());
}

quint16 TankGun::gunWidth() const
{
    return gunWidth_;
}

void TankGun::setGunWidth(const quint16 &gunWidth)
{
    gunWidth_ = gunWidth;
}

quint16 TankGun::gunHeight() const
{
    return gunHeight_;
}

void TankGun::setGunHeight(const quint16 &gunHeight)
{
    gunHeight_ = gunHeight;
}


