#ifndef TANKGUN_H
#define TANKGUN_H

#include <QObject>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>

class TankGun : public QObject, public QGraphicsItem
{
public:
    TankGun();
    TankGun(quint16, quint16);
    ~TankGun();

    quint16 gunHeight() const;
    void setGunHeight(const quint16 &gunHeight);

    quint16 gunWidth() const;
    void setGunWidth(const quint16 &gunWidth);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
signals:

public slots:

private:
    quint16 gunHeight_;
    quint16 gunWidth_;
};

#endif // TANKGUN_H
