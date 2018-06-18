#ifndef PLAYINSTANCE_H
#define PLAYINSTANCE_H

#include <QTimer>
#include <utils/loggerinterface.h>
#include <utils/gamedata/gamedata.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/gameobjectstypes.h>
#include <objects/tankcomplexobject.h>
#include <builders/director.h>
#include <utils/mapmanager.h>
#include <objects/playwindow.h>

class PlayInstance: public QObject
{
    Q_OBJECT
public:
    PlayInstance() = delete;
    ~PlayInstance() = default;
    PlayInstance(const std::shared_ptr<GameData>&, const std::shared_ptr<Logger>&);

    void start();
    void stop();
    void update();

    TankTypes playerTankType() const;
    void setPlayerTankType(const TankTypes &playerTankType);

signals:
    void stopSignal();

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Logger> logger_;

    std::unique_ptr<Director> director_;

    // 0 танк - это игрок
    std::vector<std::shared_ptr<TankComplexObject>> tanksList_;
    std::vector<std::shared_ptr<Wall>> walls_;
    std::shared_ptr<Circle> circle_;
    std::unique_ptr<QTimer> timer_;
    std::unique_ptr<MapManager> mapManager_;
    std::unique_ptr<PlayWindow> window_;
    std::shared_ptr<PlayerHUD> playerHud_;
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Physics> physics_;
    TankTypes playerTankType_;
    GameInfo gameInfo_;

    void initPlayer();
    void initCircle();
    void initMap();
    void initWalls();
    void checkGameState();
};

#endif // PLAYINSTANCE_H
