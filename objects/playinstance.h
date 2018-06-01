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
#include <builders/directors/tankbuilderdirector.h>

class PlayInstance: public QObject
{
public:
    PlayInstance();
    PlayInstance(const std::shared_ptr<GameData>&, const std::shared_ptr<Logger>&);

    void start();
    void stop();
    void update();

    TankTypes playerTankType() const;
    void setPlayerTankType(const TankTypes &playerTankType);

private:
    std::shared_ptr<GameData> gameData_;
    std::shared_ptr<Logger> logger_;

    std::unique_ptr<TankBuilderDirector> tankDirector_;
    std::vector<std::shared_ptr<TankComplexObject>> tanksList_;
    std::unique_ptr<QTimer> timer_;
    PlayInstanceWidget* playInstanceWidget_;
    QGraphicsView* camera_;
    TankTypes playerTankType_;
    GameInfo gameInfo_;

};

#endif // PLAYINSTANCE_H
