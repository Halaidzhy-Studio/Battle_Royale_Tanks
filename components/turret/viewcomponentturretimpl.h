#ifndef VIEWCOMPONENTTURRETIMPL_H
#define VIEWCOMPONENTTURRETIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/turret/logicturretcomponent.h>

class ViewComponentTurretImpl : public ViewComponent
{
public:
    ViewComponentTurretImpl() = default;
    ViewComponentTurretImpl(GraphicsItem* item,
                            const std::shared_ptr<LogicTurretComponent>&);
    ~ViewComponentTurretImpl() = default;

    GraphicsItem *getGraphicsItem() override;
    void update() override;
private:
    GraphicsItem* graphicsItem_;
    std::shared_ptr<LogicTurretComponent> logicTurret_;
};

#endif // VIEWCOMPONENTTURRETIMPL_H
