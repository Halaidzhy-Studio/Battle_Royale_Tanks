#ifndef PLAYERSINGLEPLAYERBODYBUILDER_H
#define PLAYERSINGLEPLAYERBODYBUILDER_H

#include <builders/interfaces/singleplayerbodybuilderimpl.h>
#include <utils/data/bodyinfostruct.h>
#include <components/body/bodyinfocomponent.h>
#include <components/body/viewcomponentbodyimpl.h>
#include <Graphics/graphics.h>

class PlayerSingleplayerBodyBuilder : public SingleplayerBodyBuilderImpl
{
public:
    PlayerSingleplayerBodyBuilder();
    PlayerSingleplayerBodyBuilder(TankBodyInfo tankBodyInfo,
                                  const std::shared_ptr<Graphics>& graphics);
    ~PlayerSingleplayerBodyBuilder() = default;
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;

private:
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;
    std::shared_ptr<Graphics> graphics_;
    TankBodyInfo tankBodyInfo_;
};

#endif // PLAYERSINGLEPLAYERBODYBUILDER_H
