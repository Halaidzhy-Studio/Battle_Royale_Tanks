#include "tankbody.h"

std::shared_ptr<HandleInputComponent> TankBody::handleInputComponent() const
{
    return handleInputComponent_;
}

void TankBody::setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent)
{
    handleInputComponent_ = handleInputComponent;
}

std::shared_ptr<NetworkComponent> TankBody::networkComponent() const
{
    return networkComponent_;
}

void TankBody::setNetworkComponent(const std::shared_ptr<NetworkComponent> &networkComponent)
{
    networkComponent_ = networkComponent;
}
