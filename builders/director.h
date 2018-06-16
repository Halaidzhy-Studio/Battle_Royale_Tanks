#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <objects/tankbody.h>
#include <objects/circle.h>
#include <objects/wall.h>
#include <objects/tankturret.h>
#include <builders/interfaces/builder.h>
class Director
{
public:
    Director() = default;
    std::shared_ptr<Circle> getCircle(const std::shared_ptr<Builder>&);
    std::shared_ptr<TankBody> getTankBody(const std::shared_ptr<Builder>&);
    std::shared_ptr<Wall> getWall(const std::shared_ptr<Builder>&);
    std::shared_ptr<TankTurret> getTurret(const std::shared_ptr<Builder>&);

    ~Director() = default;
};

#endif // DIRECTOR_H
