#include "utils/gamedata/gamedata.h"
#include "utils/gamedata/configextractorlibconfig.h"
#include <memory>
#include "engine.h"
#include "engineqt.h"

using namespace libconfig;

int main(int argc, char *argv[])
{
    std::shared_ptr<Engine> engineQt = std::make_shared<EngineQT>(argc, argv);

    std::shared_ptr<Logger> logger(new QtLogger);

    std::shared_ptr<ConfigExtractor> configExtractor(new ConfigExtractorLibconfig(logger));

    std::shared_ptr<GameData> gameData = GameData::createGameData(configExtractor, argv[1]);

    engineQt->setGameData(gameData);
    engineQt->setLogger(logger);
    return engineQt->startGame();

}
