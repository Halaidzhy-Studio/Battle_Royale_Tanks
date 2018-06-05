#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <objects/tankbody.h>
#include <objects/circle.h>
#include <builders/interfaces/builder.h>
class Director
{
public:
    Director() = default;
    std::shared_ptr<Circle> getCircle(const std::shared_ptr<Builder>&);
    std::shared_ptr<TankBody> getTankBody(const std::shared_ptr<Builder>&);
    ~Director() = default;
};

#endif // DIRECTOR_H
