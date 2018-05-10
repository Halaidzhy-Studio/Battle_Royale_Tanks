#ifndef GAME_H
#define GAME_H

#include <GameMenu/gamemenu.h>
#include <utils/gamedata.h>
#include <libconfig.h++>
#include <memory>

class Game
{
public:
    Game(const std::shared_ptr<GameData>& gameData) : gameData_(gameData) {}
    void startGame();

private:
    std::shared_ptr<GameData> gameData_;
    std::unique_ptr<GameMenu> gameMenu_;

};

#endif // GAME_H
