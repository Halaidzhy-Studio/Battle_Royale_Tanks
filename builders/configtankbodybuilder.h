#ifndef CONFIGTANKBODYBUILDER_H
#define CONFIGTANKBODYBUILDER_H

#include "interfaces/bodybuilder.h"
#include <objects/tankbody.h>

class ConfigTankBodyBuilder : public BodyBuilder
{
public:
    ConfigTankBodyBuilder();
    ConfigTankBodyBuilder(const TankBodyInfo& tankBodyInfo) : tankBodyInfo_(tankBodyInfo) {}


private:
    TankBodyInfo tankBodyInfo_;

};

#endif // CONFIGTANKBODYBUILDER_H
