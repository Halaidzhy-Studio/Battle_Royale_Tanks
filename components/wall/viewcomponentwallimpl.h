#ifndef VIEWCOMPONENTWALLIMPL_H
#define VIEWCOMPONENTWALLIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <Graphics/graphicsitem.h>

class ViewComponentWallImpl : public ViewComponent
{
public:
    ViewComponentWallImpl() = default;
    ViewComponentWallImpl(GraphicsItem*);
    ~ViewComponentWallImpl() = default;
    void update();
private:
     GraphicsItem* graphicsItem_;
};

#endif // VIEWCOMPONENTWALLIMPL_H
