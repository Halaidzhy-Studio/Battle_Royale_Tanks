#ifndef CONFIGTANKBODYBUILDER_H
#define CONFIGTANKBODYBUILDER_H

#include <objects/tankbody.h>
#include "components/body/handleinputcomponentimplbody.h"
#include "components/body/viewcomponentbodyimpl.h"
#include "components/body/physicscomponentbodyimpl.h"
#include "components/body/bodyinfocomponent.h"
#include "interfaces/bodybuilder.h"

class ConfigTankBodyBuilder : public BodyBuilder
{
public:
    ConfigTankBodyBuilder() = default;
    ConfigTankBodyBuilder(const TankBodyInfo& tankBodyInfo,
                          const std::shared_ptr<Graphics>& gameView,
                          const std::shared_ptr<Physics>& physicsEngine) :
        tankBodyInfo_(tankBodyInfo), gameView_(gameView), physicsEngine_(physicsEngine) {

        bodyInfoComponent_ = std::make_shared<BodyInfoComponent>(tankBodyInfo_);
/*
        handleInputComponentImpl_ = std::make_shared<HandleInputComponentImplBody>(bodyInfoComponent_);

        // handleInputComponent наследуется от ViewComponent -> имеет свойства QGraphicsItem
        gameView_->addObject(handleInputComponentImpl_.get());

        // Костыль, потому что в QT Graphics Framework используется один класс для отрисовки
        // и перхвата нажатых клавиш. QGraphicsItem, где ViewCompoponent  - QGraphicsItem
        //viewComponentImlp_ = std::dynamic_pointer_cast<ViewComponentBodyImpl>(handleInputComponentImpl_);

        //viewComponentImlp_->setStyleInfo(tankBodyInfo_);
        //viewComponentImlp_->setRectInfo(tankBodyInfo_);
        //viewComponentImlp_->setBodyInfo(bodyInfoComponent_);

        physicsComponentImpl_ = std::make_shared<PhysicsComponentBodyImpl>(tankBodyInfo_.physicsInfo, physicsEngine);
        */
    }


private:
    TankBodyInfo tankBodyInfo_;
    std::shared_ptr<Graphics> gameView_;
    std::shared_ptr<Physics> physicsEngine_;

    std::shared_ptr<HandleInputComponentImplBody> handleInputComponentImpl_;
    std::shared_ptr<ViewComponentBodyImpl> viewComponentImlp_;
    std::shared_ptr<PhysicsComponentBodyImpl> physicsComponentImpl_;
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;

    // BodyBuilder interface
public:
    std::shared_ptr<HandleInputComponent> getHandleInputComponent() override;
    std::shared_ptr<PhysicsComponent> getPhysicsComponent() override;
    std::shared_ptr<ViewComponent> getViewComponent() override;
    std::shared_ptr<NetworkComponent> getNetworkComponent(const int id) override;
};

#endif // CONFIGTANKBODYBUILDER_H
