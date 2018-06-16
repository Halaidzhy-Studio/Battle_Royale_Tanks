#include "utils/gamedata/gamedata.h"
#include "utils/gamedata/configextractor.h"
#include <memory>
#include "engine.h"
#include "engineqt.h"

using namespace libconfig;

int main(int argc, char *argv[])
{
    std::shared_ptr<Engine> engineQt = std::make_shared<EngineQT>(argc, argv);

    std::shared_ptr<Logger> logger(new QtLogger);

    std::shared_ptr<Extractor> configExtractor(new ConfigExtractor(logger, argv[1]));

    std::shared_ptr<GameData> gameData = GameData::createGameData(configExtractor);

    engineQt->setGameData(gameData);
    engineQt->setLogger(logger);

    return engineQt->startGame();

}
