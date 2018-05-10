#ifndef HANDLEINPUTCOMPONENTIMPLBODY_H
#define HANDLEINPUTCOMPONENTIMPLBODY_H

#include <components/interfaces/componentsinterfaces.h>
#include <QGraphicsItem>
class HandleInputComponentImplBody : public HandleInputComponent,
{
public:
    HandleInputComponentImplBody(QGraphicsItem);
    void update(GameObject *gameObject) override;
};

#endif // HANDLEINPUTCOMPONENTIMPLBODY_H
