#ifndef CONFIGTANKBODYBUILDER_H
#define CONFIGTANKBODYBUILDER_H

#include "interfaces/bodybuilder.h"
#include <objects/tankbody.h>

class ConfigTankBodyBuilder : public BodyBuilder
{
public:
    ConfigTankBodyBuilder() = default;
    ConfigTankBodyBuilder(const TankBodyInfo& tankBodyInfo) : tankBodyInfo_(tankBodyInfo) {}


private:
    TankBodyInfo tankBodyInfo_;


    // BodyBuilder interface
public:
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
};

#endif // CONFIGTANKBODYBUILDER_H
