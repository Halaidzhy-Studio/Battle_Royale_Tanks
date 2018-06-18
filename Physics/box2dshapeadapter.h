#ifndef BOX2DSHAPEADAPTER_H
#define BOX2DSHAPEADAPTER_H

#include <Physics/physicsshape.h>
#include <3rdparty/Box2D/Box2D.h>

class Box2dShapeAdapter : public PhysicsShape
{
public:
    Box2dShapeAdapter() = default;
    ~Box2dShapeAdapter() = default;
    void setAsBox(double w, double h) override;
    b2PolygonShape* getShape();
private:
    b2PolygonShape shape_;
};

#endif // BOX2DSHAPEADAPTER_H
