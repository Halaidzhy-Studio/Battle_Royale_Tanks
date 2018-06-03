
#ifndef TANKBUILDERDIRECTOR_H
#define TANKBUILDERDIRECTOR_H

#include <builders/interfaces/tankbuilder.h>
#include <QGraphicsItem>
#include <Box2D.h>

class TankBuilderDirector
{
public:
    TankBuilderDirector() = default;
    TankBuilderDirector(const std::shared_ptr<Graphics>& scene,
                        const std::shared_ptr<Physics>& world) : scene_(scene), world_(world) {}

    std::shared_ptr<TankComplexObject> getTank();
    void setBuilder(const std::shared_ptr<TankBuilder> &builder);

private:
    std::shared_ptr<TankBuilder> builder_;
    std::shared_ptr<Graphics> scene_;
    std::shared_ptr<Physics> world_;
};

#endif // TANKBUILDERDIRECTOR_H
