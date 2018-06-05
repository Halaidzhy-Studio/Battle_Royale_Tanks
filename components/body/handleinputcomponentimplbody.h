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

    // QGraphicsItem interface
protected:

private:

    enum {
        KEY_W = 0x01,
        KEY_S = 0x02,
        KEY_A = 0x04,
        KEY_D = 0x08,
    };

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
