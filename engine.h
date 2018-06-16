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

    enum class Keys{
        KEY_W = 0x01,
        KEY_S = 0x02,
        KEY_A = 0x04,
        KEY_D = 0x08,
        KEY_RIGHT = 0x10,
        KEY_LEFT = 0x20,
        KEY_SPACE = 0x40
    };

};

#endif // ENGINE_H
