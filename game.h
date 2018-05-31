#ifndef GAME_H
#define GAME_H


#include <utils/gamedata/gamedata.h>
#include <libconfig.h++>
#include <memory>
#include <QTimer>
#include <objects/igameobject.h>
#include <utils/data/gameinfostruct.h>
#include <GameMenu/gamemenu.h>
#include <gamewidget.h>
#include <utils/loggerinterface.h>

class GameMenu;

class Game : public QObject, public std::enable_shared_from_this<Game>
{
    Q_OBJECT
public:
    ~Game() = default;
    Game(const std::shared_ptr<GameData>& gameData,
         const std::shared_ptr<Logger>& logger);

    void startMenu();
    void startGame();
    void endGame();
    void update();

signals:
    void backToMenuSignal();
private:
    std::shared_ptr<GameData> gameData_;
    std::unique_ptr<GameMenu> gameMenu_;

    std::shared_ptr<Logger> logger_;

    std::unique_ptr<QTimer> gameTimer_;
    std::vector<Object> objectsVector_;

    std::unique_ptr<GameWidget> gameWidget_;
    GameInfo gameInfo_;

};

#endif // GAME_H
