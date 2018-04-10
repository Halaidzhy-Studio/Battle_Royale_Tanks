#include "tank.h"
#include <QRectF>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

Tank::Tank(){
}

Tank::~Tank(){

}

QRectF Tank::boundingRect() const{
    return QRectF(50, 50, 100, 100);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}


void Tank::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "W is pressed";
    keys[event->key()] = true;

}

void Tank::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;
}

void Tank::timerKeyEvent(){
    if (keys[Qt::Key_W]){

        setPos(this->x(), this->y() - 5);
    }else if (keys[Qt::Key_D]){
        setPos(this->x() + 5, this->y());
    }else if (keys[Qt::Key_S]){
        setPos(this->x(), this->y() + 5);
    }else if (keys[Qt::Key_A]){
        setPos(this->x() - 5, this->y());
    }
}
