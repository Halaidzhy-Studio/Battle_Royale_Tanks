#ifndef BODYBUILDERDIRECTOR_H
#define BODYBUILDERDIRECTOR_H
#include <builders/interfaces/bodybuilder.h>
#include <components/interfaces/componentsinterfaces.h>
#include <objects/tankbody.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>

class BodyBuilderDirector{
public:
    BodyBuilderDirector(const std::shared_ptr<Graphics>& scene,
                        const std::shared_ptr<Physics>& world) : scene_(scene), world_(world)
    {
    }
    void setBuilder(const std::shared_ptr<BodyBuilder> &builder);
    std::shared_ptr<TankBody> getBody(const int id);
    std::shared_ptr<TankBody> getBody();

private:
    std::shared_ptr<BodyBuilder> builder_;

    std::shared_ptr<Graphics> scene_;
    std::shared_ptr<Physics> world_;
};
#endif // BODYBUILDERDIRECTOR_H
