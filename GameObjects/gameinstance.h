#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <QWidget>
#include <QTimer>
#include <vector>
#include <memory>
#include <GameViews/gamescene.h>
#include <GameObjectsViews/tankview.h>
#include <GameObjectsViews/bulletview.h>
#include "GameObjects/gamephysicsengineimpl.h"
#include <libconfig.h++>

class GameInstance: public QWidget
{
public:
    GameInstance(const std::shared_ptr<libconfig::Config> config);

    void renderInterface();
    void startGame();
private:
    std::shared_ptr<libconfig::Config> config_;

    // ClientData

    GameScene* gameScene_;
    std::unique_ptr<QTimer> gameTimer_;
    std::unique_ptr<QTimer> netTimer_;

    //QObject use row pointers
    TankView* playerTankView_;

    std::vector<TankView*> allTanks_;
    std::vector<BulletView*> allBullets_;
    std::shared_ptr<GamePhysicsEngine> gamePhysicsEngine_;

    //b2World b2GameWorld_;
    //std::vector<Tank*> tanks_;

    void updateTank();
};

#endif // GAMEINSTANCE_H
