#ifndef CONFIGTANKBODYBUILDER_H
#define CONFIGTANKBODYBUILDER_H

#include <objects/tankbody.h>
#include "components/body/handleinputcomponentimplbody.h"
#include "components/body/viewcomponentbodyimpl.h"
#include "components/body/physicscomponentbodyimpl.h"
#include "components/body/bodyinfocomponent.h"

#include "interfaces/bodybuilder.h"

#include <QGraphicsScene>
#include <Box2D.h>

class ConfigTankBodyBuilder : public BodyBuilder
{
public:
    ConfigTankBodyBuilder() = default;
    ConfigTankBodyBuilder(const TankBodyInfo& tankBodyInfo,
                          const std::shared_ptr<QGraphicsScene>& scene,
                          const std::shared_ptr<b2World>& world) :
        tankBodyInfo_(tankBodyInfo), scene_(scene), world_(world) {

        bodyInfoComponent_ = std::make_shared<BodyInfoComponent>(tankBodyInfo_);
        handleInputComponentImpl_ = std::make_shared<HandleInputComponentImplBody>(bodyInfoComponent_);

        // Костыль, потому что в QT Graphics Framework используется один класс для отрисовки
        // и перхвата нажатых клавиш. QGraphicsItem, где ViewCompoponent  - QGraphicsItem
        viewComponentImlp_ = std::dynamic_pointer_cast<ViewComponentBodyImpl>(handleInputComponentImpl_);
        viewComponentImlp_->setStyleInfo(tankBodyInfo_);
        viewComponentImlp_->setRectInfo(tankBodyInfo_);

        physicsComponentImpl_ = std::make_shared<PhysicsComponent>(tankBodyInfo_);
    }


private:
    TankBodyInfo tankBodyInfo_;
    std::shared_ptr<QGraphicsScene> scene_;
    std::shared_ptr<b2World> world_;

    std::shared_ptr<HandleInputComponentImplBody> handleInputComponentImpl_;
    std::shared_ptr<ViewComponentBodyImpl> viewComponentImlp_;
    std::shared_ptr<PhysicsComponentBodyImpl> physicsComponentImpl_;
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;

    // BodyBuilder interface
public:
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
};

#endif // CONFIGTANKBODYBUILDER_H
