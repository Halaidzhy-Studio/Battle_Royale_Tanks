#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H

#include <QWidget>
#include <gamescene.h>
#include <vector>

class GameInstance: public QWidget
{
public:
    GameInstance();

private:
    // ClientData

    GameScene* gameScene_;
    QTimer* gameTimer_;
    QTimer* netTimer_;

    //b2World b2GameWorld_;
    //std::vector<Tank*> tanks_;

};

#endif // GAMEINSTANCE_H
