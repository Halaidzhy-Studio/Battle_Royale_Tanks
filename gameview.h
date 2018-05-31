#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <memory>

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>

class GameView{
public:
    GameView();
    void addObject(QGraphicsItem* item);
private:
    std::shared_ptr<QGraphicsScene> gameScene_;
};
#endif // GAMEVIEW_H
