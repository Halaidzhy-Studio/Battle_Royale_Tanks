#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>
#include <QMap>
#include <QTimer>

#include "tankgun.h"

class Tank: public QObject, public QGraphicsItem{
public:
    enum class TankType { Simple };

    Tank();
    Tank(TankType tankType = TankType::Simple);
    ~Tank();

public slots:
    void timerKeyEvent();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    TankGun* tankGun_;
    quint16 tankWidth_;
    quint16 tankHeight_;
    qreal speed_;
    qreal angle_;
    qreal gunAngle_;
    qreal gunAngleSpeed_;
    QMap<int, bool> keys_;
    QTimer timer_;
    int hp_;
    TankType tankType_;

};
#endif // TANK_H
