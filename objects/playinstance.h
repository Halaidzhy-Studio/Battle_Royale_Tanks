#ifndef PLAYINSTANCE_H
#define PLAYINSTANCE_H

#include <QTimer>
#include <utils/loggerinterface.h>
#include <utils/gamedata/gamedata.h>
#include <Graphics/graphics.h>
#include <Physics/physics.h>
#include <utils/gameobjectstypes.h>
#include <objects/tankcomplexobject.h>
#include <objects/playinstancewidget.h>
#include <builders/director.h>
#include <utils/mapmanager.h>

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

    // Test need to delete
    std::shared_ptr<TankBody> testBody_;
    std::unique_ptr<Director> director_;

    std::vector<std::shared_ptr<TankComplexObject>> tanksList_;
    std::shared_ptr<Wall> wall_;
    std::shared_ptr<Circle> circle_;
    std::unique_ptr<QTimer> timer_;
    std::unique_ptr<MapManager> mapManager_;
    std::unique_ptr<PlayInstanceWidget> playInstanceWidget_;
    std::shared_ptr<Graphics> graphics_;
    TankTypes playerTankType_;
    GameInfo gameInfo_;

    void initPlayer();
    void initCircle();
    void initMap();
};

#endif // PLAYINSTANCE_H
