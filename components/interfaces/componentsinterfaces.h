#ifndef COMPONENTSINTERFACES_H
#define COMPONENTSINTERFACES_H

#include <objects/possibilityinterfaces.h>
#include <Graphics/graphicsitem.h>

class HandleInputComponent{
public:
    virtual ~HandleInputComponent() = default;

    virtual void update() = 0;
    virtual void initCommand() = 0;
};

class ViewComponent{
public:
    virtual ~ViewComponent() = default;
    virtual GraphicsItem* getGraphicsItem() {}
    virtual void update() = 0;
    virtual void close() {}
    virtual Coordinate getPos() {}
};

class PhysicsComponent{
public:
    virtual ~PhysicsComponent() = default;
    virtual void setPos(const Coordinate&) {}
    virtual void update() = 0;
};

class NetworkComponent {
public:
    virtual ~NetworkComponent() = default;
    virtual void update() = 0;
    virtual void setId() = 0;
};

enum class ContactEntityTypes{
    CIRCLE, BODY
};

class ContactEntity{
public:
    virtual ~ContactEntity() = default;
    virtual ContactEntityTypes getEntityType() = 0;
};

class ContactComponent {
public:
    virtual ~ContactComponent() = default;
    virtual void contactObject(std::shared_ptr<ContactEntity>) = 0;
};

#endif // COMPONENTSINTERFACES_H
