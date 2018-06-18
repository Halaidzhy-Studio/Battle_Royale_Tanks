#ifndef BOX2DPHYSICSADAPTER_H
#define BOX2DPHYSICSADAPTER_H

#include <3rdparty/Box2D/Box2D.h>
#include <Physics/physics.h>
#include <utils/gamedata/gamedata.h>

class Box2dPhysicsAdapter : public Physics
{
public:
    Box2dPhysicsAdapter(const std::shared_ptr<GameData>&,
                        const std::shared_ptr<Logger>&);
    ~Box2dPhysicsAdapter() = default;
    std::shared_ptr<PhysicsBody> createBody(PhysicsBodyDef &) override;

    void update() override;

    static b2BodyDef convertTob2BodyDef(const PhysicsBodyDef&);
    static b2FixtureDef convertTob2FixtureDef (const FixtureDef&);
    static b2MassData convertTob2MassData(const MassData&);
private:
    std::unique_ptr<b2World> world_;
    std::shared_ptr<Logger> logger_;
    WorldPhysicsInfo info_;
};

#endif // BOX2DPHYSICSADAPTER_H
