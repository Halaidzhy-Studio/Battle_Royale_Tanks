#ifndef HANDLEINPUTCOMPONENTIMPLBODY_H
#define HANDLEINPUTCOMPONENTIMPLBODY_H

#include <components/interfaces/componentsinterfaces.h>
#include <objects/commands/command.h>
#include <components/body/logicbodycomponent.h>
#include <Graphics/graphicsitem.h>

class HandleInputComponentImplBody : public HandleInputComponent
{
public:
    HandleInputComponentImplBody() = default;
    HandleInputComponentImplBody(GraphicsItem* item,
                                 const std::shared_ptr<LogicBodyComponent> bodyInfoComponent_,
                                 const std::shared_ptr<Logger>& logger_);

    void update() override;
    void initCommand() override;
private:

    std::shared_ptr<Command> keyW_;
    std::shared_ptr<Command> keyD_;
    std::shared_ptr<Command> keyA_;
    std::shared_ptr<Command> keyS_;

    int keys_;
    GraphicsItem* item_;
    std::shared_ptr<LogicBodyComponent> bodyInfoComponent_;
    std::shared_ptr<Logger> logger_;
};

#endif // HANDLEINPUTCOMPONENTIMPLBODY_H
