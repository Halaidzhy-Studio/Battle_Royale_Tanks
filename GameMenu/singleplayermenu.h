    #ifndef SINGLEPLAYERMENU_H
#define SINGLEPLAYERMENU_H

#include <QWidget>
#include <QPushButton>
#include <memory>
#include <utils/gamedata/gamedata.h>
#include <utils/data/menu/singleplayermenuinfostruct.h>
#include "game.h"
// потому что вызыватся из GameMenu, который в свою очередь первый раз вызывает из Game.
class Game;

class SingleplayerMenu: public QWidget
{
    Q_OBJECT

public:
    explicit SingleplayerMenu(const std::shared_ptr<GameData>& gameData,
                              const std::shared_ptr<Game>& game,
                              QWidget* parent = nullptr);
    ~SingleplayerMenu();
signals:
    void mainWindow();

private slots:
    void backToMainWindow();
    void startGame();

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Game> game_;
    SingleplayerMenuInfo singleplayernMenuInfo_;
    QPushButton* startGameBTN_;
    QPushButton* backToMainWindowBTN_;
};

#endif // SINGLEPLAYERMENU_H
