#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "GameMenu/gamemenu.h"
#include "utils/logger.h"
#include "utils/gamedata.h"
#include "utils/configgamedata.h"
#include <libconfig.h++>
#include <memory>
#include "game.h"
using namespace libconfig;

//#include "playwidget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<ConfigGameData> gameConfig(new ConfigGameData());
    gameConfig->upload("/home/sinimawath/QtProjects/Battle-Royale-Tank/Resources/config.cfg");

    std::shared_ptr<GameData> gameData = std::dynamic_pointer_cast<GameData>(gameConfig);
    Game game(gameData);
    game.startGame();
    return a.exec();
}
