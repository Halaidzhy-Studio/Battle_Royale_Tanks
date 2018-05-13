#include "tankbody.h"

std::shared_ptr<HandleInputComponent> TankBody::handleInputComponent() const
{
    return handleInputComponent_;
}

void TankBody::setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent)
{
    handleInputComponent_ = handleInputComponent;
}
