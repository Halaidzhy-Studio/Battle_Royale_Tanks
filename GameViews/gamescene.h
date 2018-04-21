#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <Box2D.h>
#include <memory>
#include <GameObjects/gamephysicsengine.h>

class GameScene : public QGraphicsScene
{
public:
    GameScene() = delete;
    GameScene(std::shared_ptr<GamePhysicsEngine>& gamePhysics);
public slots:
    void advance();
private:
    std::shared_ptr<GamePhysicsEngine> gamePhysics_;
};

#endif // GAMESCENE_H
