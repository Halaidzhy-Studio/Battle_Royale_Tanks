#ifndef VIEWCOMPONENTBODYIMPL_H
#define VIEWCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <QGraphicsRectItem>
#include <utils/data/bodyinfostruct.h>
#include <objects/igameobject.h>
#include <QPainter>
#include "bodyinfocomponent.h"

class ViewComponentBodyImpl : public ViewComponent, QGraphicsRectItem
{
public:
    ViewComponentBodyImpl();
    ViewComponentBodyImpl(const StyleInfo& styleInfo, const RectInfo& rectInfo,
                          const std::shared_ptr<BodyInfoComponent>&  bodyInfo) :
        styleInfo_(styleInfo), rectInfo_(rectInfo), bodyInfo_(bodyInfo) {  }

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
    std::shared_ptr<BodyInfoComponent> bodyInfo_;
};

#endif // VIEWCOMPONENTBODYIMPL_H