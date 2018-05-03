#ifndef GAMEPHYSICSENGINE_H
#define GAMEPHYSICSENGINE_H


class GamePhysicsEngine
{
public:
    GamePhysicsEngine();
    virtual void updateGame() = 0;
    virtual void createObjectInWorld(GameObject& gameObject) = 0;
};

#endif // GAMEPHYSICSENGINE_H
