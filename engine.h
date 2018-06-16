#ifndef ENGINE_H
#define ENGINE_H

#include "utils/gamedata/gamedata.h"
#include <utils/loggerinterface.h>
#include <memory>

class Engine
{
public:
    virtual ~Engine() = default;
    virtual void setGameData(const std::shared_ptr<GameData>&) = 0;
    virtual void setLogger(const std::shared_ptr<Logger>&) = 0;
    virtual int startGame() = 0;
};

#endif // ENGINE_H
