#ifndef SIMPLEOFFLINECIRCLEBUILDER_H
#define SIMPLEOFFLINECIRCLEBUILDER_H

#include <builders/interfaces/offlinebuilderimpl.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/data/circleinfostruct.h>
#include <utils/logger.h>
#include <components/circle/logiccirclecomponent.h>
#include <objects/playerhud.h>

class SimpleOfflineCircleBuilder : public OfflineBuilderImpl
{
public:
    SimpleOfflineCircleBuilder(const std::shared_ptr<Graphics>&,
                               const std::shared_ptr<Physics>&,
                               const std::shared_ptr<Logger>&,
                               const CircleInfo&,
                               const std::shared_ptr<PlayerHUD>&);

    ~SimpleOfflineCircleBuilder() = default;
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<Logger> logger_;
    std::shared_ptr<LogicCircleComponent> logicCircle_;
    CircleInfo info_;
};

#endif // SIMPLEOFFLINECIRCLEBUILDER_H
