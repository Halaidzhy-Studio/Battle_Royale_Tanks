#ifndef VIEWCOMPONENTBODYIMPL_H
#define VIEWCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <QGraphicsRectItem>
#include <utils/data/bodyinfostruct.h>
#include <objects/igameobject.h>

class ViewComponentBodyImpl : public ViewComponent, QGraphicsRectItem
{
public:
    ViewComponentBodyImpl();
    ViewComponentBodyImpl(const StyleInfo& styleInfo, const RectInfo& rectInfo) :
        styleInfo_(styleInfo), rectInfo_(rectInfo) {  }

    ~ViewComponentBodyImpl() {}

    // QGraphicsItem interface
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public:
    void update(GameObject *gameObject) override;

private:
    StyleInfo styleInfo_;
    RectInfo rectInfo_;
};

#endif // VIEWCOMPONENTBODYIMPL_H
