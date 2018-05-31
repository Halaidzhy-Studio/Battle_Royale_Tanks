#include "configtankbodybuilder.h"

std::shared_ptr<HandleInputComponent> ConfigTankBodyBuilder::getHandleInputComponent()
{   
    return std::dynamic_pointer_cast<HandleInputComponent>(handleInputComponentImpl_);
}

std::shared_ptr<PhysicsComponent> ConfigTankBodyBuilder::getPhysicsComponent()
{
    return std::dynamic_pointer_cast<PhysicsComponent>(physicsComponentImpl_);
}

std::shared_ptr<ViewComponent> ConfigTankBodyBuilder::getViewComponent()
{
    return std::dynamic_pointer_cast<ViewComponent>(viewComponentImlp_);
}

std::shared_ptr<NetworkComponent> ConfigTankBodyBuilder::getNetworkComponent(const int id)
{
    return nullptr;
}
