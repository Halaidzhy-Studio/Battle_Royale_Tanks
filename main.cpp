#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "GameMenu/gamemenu.h"
#include "utils/tanktype.h"
#include "utils/logger.h"
#include <libconfig.h++>
#include <memory>
#include "game.h"
using namespace libconfig;

//#include "playwidget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<Config> gameConfig(new Config);
    try{
        gameConfig->readFile("/home/sinimawath/QtProjects/Battle-Royale-Tank/Resources/config.cfg");
    } catch(const FileIOException &ex){
        Logger::instance().printLog("I/O while reading config" + std::string(ex.what()), Logger::loggerGame);
        return(EXIT_FAILURE);
    } catch(const ParseException &ex){
        std::string result = "Parese error at " + std::string(ex.getFile()) + " : " +
                std::to_string(ex.getLine()) + " - " + std::string(ex.getError()) + "\n";
        Logger::instance().printLog(result, Logger::loggerGame);
        return (EXIT_FAILURE);
    }

    Game game(gameConfig);
    game.startGame();
    return a.exec();
}
