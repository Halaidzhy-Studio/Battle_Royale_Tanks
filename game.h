#ifndef GAME_H
#define GAME_H

#include <GameMenu/gamemenu.h>
#include <libconfig.h++>
#include <memory>

class Game
{
public:
    Game(const std::shared_ptr<libconfig::Config>& config);
    void startGame();
private:
    std::shared_ptr<libconfig::Config> config_;
    std::unique_ptr<GameMenu> gameMenu_;

};

#endif // GAME_H
