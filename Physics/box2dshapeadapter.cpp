#include "box2dshapeadapter.h"


void Box2dShapeAdapter::setAsBox(double w, double h)
{
    shape_.SetAsBox(w, h);
}

b2PolygonShape* Box2dShapeAdapter::getShape()
{
    return &shape_;
}
