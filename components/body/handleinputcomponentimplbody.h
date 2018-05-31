#ifndef HANDLEINPUTCOMPONENTIMPLBODY_H
#define HANDLEINPUTCOMPONENTIMPLBODY_H

#include <components/interfaces/componentsinterfaces.h>
#include <QGraphicsItem>
#include "viewcomponentbodyimpl.h"
#include <objects/commands/command.h>
#include "bodyinfocomponent.h"
#include <QKeyEvent>

class HandleInputComponentImplBody : public HandleInputComponent, public ViewComponentBodyImpl
{
public:
    HandleInputComponentImplBody() = default;
    HandleInputComponentImplBody(const std::shared_ptr<BodyInfoComponent> bodyInfoComponent_);
    void update(Controlable *gameObject) override;
    void setObject(Controlable *gameObject) override;
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

    Controlable* gameObject_;

    int keys_;
    std::shared_ptr<BodyInfoComponent> bodyInfoComponent_;


    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // HANDLEINPUTCOMPONENTIMPLBODY_H
