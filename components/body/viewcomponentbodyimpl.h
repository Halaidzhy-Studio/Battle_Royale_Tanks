#ifndef VIEWCOMPONENTBODYIMPL_H
#define VIEWCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <QGraphicsRectItem>
#include <utils/data/bodyinfostruct.h>
#include <objects/igameobject.h>
#include <QPainter>
#include <Graphics/graphics.h>
#include <Graphics/graphicsitem.h>
#include "bodyinfocomponent.h"

class ViewComponentBodyImpl : public ViewComponent
{
public:

    ViewComponentBodyImpl() = default;
    ViewComponentBodyImpl(const StyleInfo& styleInfo, const RectInfo& rectInfo,
                          const std::shared_ptr<BodyInfoComponent>&  bodyInfo) :
        styleInfo_(styleInfo), rectInfo_(rectInfo), bodyInfo_(bodyInfo) {  }

    ViewComponentBodyImpl(GraphicsItem* graphicsItem,
                          const std::shared_ptr<BodyInfoComponent>&  bodyInfo):
        graphicsItem_(graphicsItem), bodyInfo_(bodyInfo) {}

    ~ViewComponentBodyImpl() {}

    void update(GameObject *gameObject) override;

private:
    StyleInfo styleInfo_;
    RectInfo rectInfo_;
    GraphicsItem* graphicsItem_;
    std::shared_ptr<BodyInfoComponent> bodyInfo_;
};

#endif // VIEWCOMPONENTBODYIMPL_H
