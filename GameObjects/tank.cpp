#include <QRectF>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
#include "tank.h"
#include "tankgun.h"

Tank::Tank():speed_(0), angle_(0), hp_(3){
}

Tank::Tank(Tank::TankType tankType)
{
    if (tankType == TankType::Simple){
        tankWidth_ = 100;
        tankHeight_ = 120;
        speed_ = 4;
        angle_ = 0;
        hp_ =3;
        gunAngleSpeed_ = 1;
        gunAngle_ = 0;

        tankGun_ = new TankGun(20, 45);

    }

    tankGun_->setParentItem(this);
    tankGun_->setPos(tankWidth_/2 - tankGun_->gunWidth()/2, tankHeight_/2);
}



Tank::~Tank(){

}

QRectF Tank::boundingRect() const{
    return QRectF(0, 0, tankWidth_, tankHeight_);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());

}


void Tank::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "W is pressed";
    keys_[event->key()] = true;

}

void Tank::keyReleaseEvent(QKeyEvent *event)
{
    keys_[event->key()] = false;
}

void Tank::timerKeyEvent(){
    if (keys_[Qt::Key_W]){
        setPos(this->x(), this->y() - 5);
    }else if (keys_[Qt::Key_D]){
        setPos(this->x() + 5, this->y());
    }else if (keys_[Qt::Key_S]){
        setPos(this->x(), this->y() + 5);
    }else if (keys_[Qt::Key_A]){
        setPos(this->x() - 5, this->y());

    }

}
