#ifndef BODYBUILDERDIRECTOR_H
#define BODYBUILDERDIRECTOR_H
#include <builders/interfaces/bodybuilder.h>
#include <components/interfaces/componentsinterfaces.h>
#include <objects/tankbody.h>

#include <QGraphicsScene>
#include <Box2D.h>

class BodyBuilderDirector{
public:
    BodyBuilderDirector(const std::shared_ptr<QGraphicsScene>& scene,
                        const std::shared_ptr<b2World>& world) : scene_(scene), world_(world)
    {

    }
    void setBuilder(const std::shared_ptr<BodyBuilder> &builder);
    std::shared_ptr<TankBody> getBody();
private:
    std::shared_ptr<BodyBuilder> builder_;

    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<b2World> world_;
};
#endif // BODYBUILDERDIRECTOR_H
