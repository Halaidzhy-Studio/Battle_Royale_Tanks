#include "circle.h"

void Circle::update()
{
    if (handleInputComponent_){
        handleInputComponent_->update();
    }
    if (networkComponent_){
        networkComponent_->update();
    }
}

std::shared_ptr<HandleInputComponent> Circle::handleInputComponent() const
{
    return handleInputComponent_;
}

void Circle::setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent)
{
    handleInputComponent_ = handleInputComponent;
}

std::shared_ptr<NetworkComponent> Circle::networkComponent() const
{
    return networkComponent_;
}

void Circle::setNetworkComponent(const std::shared_ptr<NetworkComponent> &networkComponent)
{
    networkComponent_ = networkComponent;
}
