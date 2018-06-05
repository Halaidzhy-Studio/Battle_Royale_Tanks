#ifndef VIEWCOMPONENTCIRCLEIMPL_H
#define VIEWCOMPONENTCIRCLEIMPL_H

#include <memory>
#include <components/interfaces/componentsinterfaces.h>
#include <components/circle/logiccirclecomponent.h>
#include <utils/logger.h>
#include <Graphics/graphicsitem.h>

class ViewComponentCircleImpl : public ViewComponent
{
public:
    ViewComponentCircleImpl() = delete;
    ViewComponentCircleImpl(const std::shared_ptr<GraphicsItem>&,
                            const std::shared_ptr<LogicCircleComponent>&,
                            const std::shared_ptr<Logger>&);
    
    ~ViewComponentCircleImpl() = default;
    void update() override;

private:
    std::shared_ptr<GraphicsItem> graphicsItem_;
    std::shared_ptr<LogicCircleComponent> logicCircle_;
    std::shared_ptr<Logger> logger_;
};

#endif // VIEWCOMPONENTCIRCLEIMPL_H
