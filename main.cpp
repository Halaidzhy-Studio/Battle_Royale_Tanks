#include "utils/gamedata/gamedata.h"
#include "utils/gamedata/configgamedata.h"
#include <memory>
#include "engine.h"
#include "engineqt.h"

using namespace libconfig;

int main(int argc, char *argv[])
{

    std::shared_ptr<Engine> engineQt = std::make_shared<EngineQT>(argc, argv);
    std::shared_ptr<ConfigGameData> gameConfig(new ConfigGameData());
    gameConfig->upload("/home/sinimawath/QtProjects/Battle-Royale-Tank/Resources/config.cfg");

    std::shared_ptr<GameData> gameData = gameConfig->createGameData();


    engineQt->setGameData(gameData);

    return engineQt->startGame();

}
