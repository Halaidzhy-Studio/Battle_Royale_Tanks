#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "GameMenu/gamemenu.h"
#include "utils/tanktype.h"
#include "utils/logger.h"
#include <libconfig.h++>

using namespace libconfig;

//#include "playwidget.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Config gameConfig;
    try{
        gameConfig.readFile("config.cfg");
    } catch(const FileIOException &ex){
        Logger::instance().printLog("I/O while reading config", Logger::loggerGame);
        return(EXIT_FAILURE);
    } catch(const ParseException &ex){
        std::string result = "Parese error at " + std::string(ex.getFile()) + " : " +
                std::to_string(ex.getLine()) + " - " + std::string(ex.getError()) + "\n";
        Logger::instance().printLog(result, Logger::loggerGame);
        return (EXIT_FAILURE);
    }

    GameMenu gamemenu;
    gamemenu.show();
    return a.exec();
}
