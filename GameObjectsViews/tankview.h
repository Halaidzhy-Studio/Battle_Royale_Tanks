#ifndef TANKVIEW_H
#define TANKVIEW_H

#include <QGraphicsItem>
#include <GameObjects/tank.h>
#include "tankturretview.h"

class TankView : public QGraphicsItem
{
public:
    TankView() = delete;
    TankView(Tank* tank, TankTurretView* tankTurretView);
    ~TankView();
    // QGraphicsItem interface
public:
    void advance(int phase) override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Tank* tank_;
    TankTurretView* tankTurretView_;
    // Must be Texture, but not in minimal version
};

#endif // TANKVIEW_H
