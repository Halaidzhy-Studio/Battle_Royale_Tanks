#ifndef BODYBUILDERDIRECTOR_H
#define BODYBUILDERDIRECTOR_H
#include <builders/interfaces/bodybuilder.h>
#include <objects/tankbody.h>

class BodyBuilderDirector{
public:
    BodyBuilderDirector();
    void setBuilder(const std::shared_ptr<BodyBuilder> &builder);
    std::shared_ptr<TankBody> getBody();

private:
    std::shared_ptr<BodyBuilder> builder_;
};
#endif // BODYBUILDERDIRECTOR_H
