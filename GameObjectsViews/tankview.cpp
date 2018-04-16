#include "tankview.h"
#include <QPainter>
#include <QPen>

TankView::TankView(Tank* tank, TankTurretView* tankTurretView): tank_(tank),
    tankTurretView_(tankTurretView)
{
    tankTurretView_->setParentItem(this);
}

TankView::~TankView()
{

}

void TankView::advance(int phase)
{

}

QRectF TankView::boundingRect() const
{

    //QRectF tankRect( -tank_.width()/2, -tank_.height()/2, tank_.width(), tank_.height());
    //return tankRect;
}

void TankView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->drawRect(boundingRect());

}

void TankView::keyPressEvent(QKeyEvent *event)
{

}

void TankView::keyReleaseEvent(QKeyEvent *event)
{

}
