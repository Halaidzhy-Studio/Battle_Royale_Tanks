#ifndef CIRCLE_H
#define CIRCLE_H

#include <objects/igameobject.h>

class Circle : public GameObject
{
public:
    Circle() = default;
    ~Circle() = default;
    void update() override;
    std::shared_ptr<HandleInputComponent> handleInputComponent() const;
    void setHandleInputComponent(const std::shared_ptr<HandleInputComponent> &handleInputComponent);

    std::shared_ptr<NetworkComponent> networkComponent() const;
    void setNetworkComponent(const std::shared_ptr<NetworkComponent> &networkComponent);

    std::shared_ptr<ContactComponent> contactComponent() const;
    void setContactComponent(const std::shared_ptr<ContactComponent> &contactComponent);

private:
    std::shared_ptr<HandleInputComponent> handleInputComponent_;
    std::shared_ptr<NetworkComponent> networkComponent_;
    std::shared_ptr<ContactComponent> contactComponent_;
};

#endif // CIRCLE_H
