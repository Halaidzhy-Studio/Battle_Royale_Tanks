#include "tankturret.h"



std::shared_ptr<HandleInputComponent> TankTurret::handleInputComponent() const
{
    return handleInputComponent_;
}

void TankTurret::setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent)
{
    handleInputComponent_ = handleInputComponent;
}


void TankTurret::shoot()
{
}

void TankTurret::turnR()
{
}

void TankTurret::turnL()
{
}

void TankTurret::turnTo(int angle)
{
}
