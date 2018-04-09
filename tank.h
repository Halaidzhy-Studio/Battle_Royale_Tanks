#ifndef TANK_H
#define TANK_H
#include <QGraphicsItem>
#include <QMap>
#include <QTimer>

class Tank: public QObject, public QGraphicsItem{
public:
    Tank();
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
    qreal speed;
    qreal angle;
    qreal gunAngle;
    QMap<int, bool> keys;
    QTimer timer;
    int hp;

};
#endif // TANK_H
