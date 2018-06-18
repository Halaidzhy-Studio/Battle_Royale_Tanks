#ifndef PHYSICSCOMPONENTWALLIMPL_H
#define PHYSICSCOMPONENTWALLIMPL_H

#include <Physics/physics.h>
#include <Physics/physicsbody.h>
#include <Physics/physicsfixture.h>
#include <utils/data/wallinfostruct.h>
#include <components/interfaces/componentsinterfaces.h>

class PhysicsComponentWallImpl : public PhysicsComponent
{
public:
    PhysicsComponentWallImpl() = default;
    PhysicsComponentWallImpl(const std::shared_ptr<Physics>&,
                             const std::shared_ptr<Logger>&,
                             const WallInfo&);

    ~PhysicsComponentWallImpl() = default;

    void update() override;
private:
    std::shared_ptr<Physics> physics_;
    std::shared_ptr<Logger> logger_;
    WallInfo info_;
    std::shared_ptr<PhysicsBody> body_;
};

#endif // PHYSICSCOMPONENTWALLIMPL_H
