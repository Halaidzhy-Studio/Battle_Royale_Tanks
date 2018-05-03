#ifndef TANK_H
#define TANK_H

#include "GameObjects/gameobject.h"

class Tank : public GameObject
{
public:
    Tank();
    void createInWorld(b2World *&world);
private:
    int hp_;
    int speed_;
    int angularSpeed_;
    int damage_;
    int bulletRecharge_;

    b2Body* body_;
    b2BodyDef bodyDef;
    b2FixtureDef fixDef_;
    b2PolygonShape shape_;
    b2RevoluteJointDef revoluteJoint_;
};

#endif // TANK_H
