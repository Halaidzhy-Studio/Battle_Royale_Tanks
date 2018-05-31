#ifndef BODYBUILDERDIRECTOR_H
#define BODYBUILDERDIRECTOR_H
#include <builders/interfaces/bodybuilder.h>
#include <components/interfaces/componentsinterfaces.h>
#include <objects/tankbody.h>
#include "gameview.h"
#include "physicsengine.h"

class BodyBuilderDirector{
public:
    BodyBuilderDirector(const std::shared_ptr<GameView>& scene,
                        const std::shared_ptr<PhysicsEngine>& world) : scene_(scene), world_(world)
    {
    }
    void setBuilder(const std::shared_ptr<BodyBuilder> &builder);
    std::shared_ptr<TankBody> getBody(const int id);

private:
    std::shared_ptr<BodyBuilder> builder_;

    std::shared_ptr<GameView> scene_;
    std::shared_ptr<PhysicsEngine> world_;
};
#endif // BODYBUILDERDIRECTOR_H
