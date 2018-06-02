#ifndef BODYBUILDERDIRECTOR_H
#define BODYBUILDERDIRECTOR_H
#include <builders/interfaces/bodybuilder.h>
#include <components/interfaces/componentsinterfaces.h>
#include <objects/tankbody.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>

class BodyBuilderDirector{
public:
    BodyBuilderDirector() = default;
    ~BodyBuilderDirector() = default;
    void setBuilder(const std::shared_ptr<BodyBuilder> &builder);
    std::shared_ptr<TankBody> getBody();
private:
    std::shared_ptr<BodyBuilder> builder_;
};
#endif // BODYBUILDERDIRECTOR_H
