#ifndef CONTACTCOMPONENTCIRCLEIMPL_H
#define CONTACTCOMPONENTCIRCLEIMPL_H

#include <components/interfaces/componentsinterfaces.h>
#include <objects/tankcomplexobject.h>
#include <components/circle/logiccirclecomponent.h>
#include <vector>

class ContactComponentCircleImpl : public ContactComponent, public QObject
{
public:
    ContactComponentCircleImpl() = default;
    ContactComponentCircleImpl(const std::shared_ptr<LogicCircleComponent>&,
                               const std::shared_ptr<Logger>&,
                               const std::vector<std::shared_ptr<TankComplexObject>>&);

    ~ContactComponentCircleImpl() = default;
    void contactObject(std::shared_ptr<ContactEntity>) override;

private:
    std::shared_ptr<LogicCircleComponent> logicComponent_;
    std::shared_ptr<Logger> logger_;
    std::vector<std::shared_ptr<TankComplexObject>> tanks_;
    std::unique_ptr<QTimer> checkTimer_;
    void checkContactsWithTanks();
};

#endif // CONTACTCOMPONENTCIRCLEIMPL_H
