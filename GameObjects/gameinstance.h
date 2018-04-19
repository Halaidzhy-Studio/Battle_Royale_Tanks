#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <QWidget>
#include <QTimer>
#include <vector>
#include <memory>
#include <GameViews/gamescene.h>
#include "GameObjects/gamephysicsengineimpl.h"
class GameInstance: public QWidget
{
public:
    GameInstance();

private:
    // ClientData

    GameScene* gameScene_;
    std::unique_ptr<QTimer> gameTimer_;
    std::unique_ptr<QTimer> netTimer_;

    std::shared_ptr<GamePhysicsEngine> gamePhysicsEngine_;
    //b2World b2GameWorld_;
    //std::vector<Tank*> tanks_;

};

#endif // GAMEINSTANCE_H
