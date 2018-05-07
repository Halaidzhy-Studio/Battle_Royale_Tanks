#include "tankbody.h"

std::shared_ptr<HandleInputComponent> TankBody::handleInputComponent() const
{
    return handleInputComponent_;
}

void TankBody::setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent)
{
    handleInputComponent_ = handleInputComponent;
}

void TankBody::turnR()
{
}

void TankBody::turnL()
{
}

void TankBody::turnTo(int angle)
{
}

void TankBody::moveF()
{
}

void TankBody::moveB()
{
}

void TankBody::moveTo(int x, int y)
{
}
