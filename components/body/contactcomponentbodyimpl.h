#ifndef CONTACTCOMPONENTBODYIMPL_H
#define CONTACTCOMPONENTBODYIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <components/body/logicbodycomponent.h>
#include <objects/commands/command.h>

class ContactComponentBodyImpl : public ContactComponent
{
public:
    ContactComponentBodyImpl() = default;
    ContactComponentBodyImpl(const std::shared_ptr<LogicBodyComponent>&,
                             const std::shared_ptr<Logger>&);
    ~ContactComponentBodyImpl() = default;

    void contactObject(std::shared_ptr<ContactEntity>) override;

private:
    std::shared_ptr<LogicBodyComponent> logicComponent_;
    std::shared_ptr<Logger> logger_;

    void initCommands();
    void circleContact(const std::shared_ptr<ContactEntity>&);
};

#endif // CONTACTCOMPONENTBODYIMPL_H
