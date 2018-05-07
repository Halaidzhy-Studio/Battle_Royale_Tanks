#ifndef TANKBUILDERDIRECTOR_H
#define TANKBUILDERDIRECTOR_H

#include <builders/interfaces/tankbuilder.h>

class TankBuilderDirector
{
public:
    TankBuilderDirector() = default;
    std::shared_ptr<TankComplexObject> getTank();
    void setBuilder(const std::shared_ptr<TankBuilder> &builder);

private:
    std::shared_ptr<TankBuilder> builder_;

};

#endif // TANKBUILDERDIRECTOR_H
