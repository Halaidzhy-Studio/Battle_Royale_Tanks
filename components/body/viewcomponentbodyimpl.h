#ifndef VIEWCOMPONENTBODYIMPL_H
#define VIEWCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <objects/igameobject.h>
#include <Graphics/graphicsitem.h>
#include "logicbodycomponent.h"

class ViewComponentBodyImpl : public ViewComponent
{
public:

    ViewComponentBodyImpl() = default;
    ViewComponentBodyImpl(GraphicsItem* graphicsItem,
                          const std::shared_ptr<LogicBodyComponent>&  bodyInfo);

    ~ViewComponentBodyImpl() = default;

    void update() override;
    GraphicsItem* getGraphicsItem() override;
private:
    GraphicsItem* graphicsItem_;
    std::shared_ptr<LogicBodyComponent> bodyInfo_;
};

#endif // VIEWCOMPONENTBODYIMPL_H
