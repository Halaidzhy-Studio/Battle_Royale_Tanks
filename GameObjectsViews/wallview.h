#ifndef WALLVIEW_H
#define WALLVIEW_H

#include <QGraphicsItem>
#include "GameObjects/wall.h"

class WallView : public QGraphicsItem
{
public:
    WallView() = default;
    WallView(Wall* wall);

    ~WallView();
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
private:
    Wall* wall_;

};

#endif // WALLVIEW_H
