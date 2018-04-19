#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <Box2D.h>

class GameScene : public QGraphicsScene
{
public:
    GameScene();
private:
    b2World* b2GameWorld_;
};

#endif // GAMESCENE_H
