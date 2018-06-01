#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <memory>
class Graphics
{
public:
    Graphics();
    void setSceneRect(int xp, int yp, int x, int y);
    void addItem(QGraphicsItem* item);
    void setControlable(QGraphicsItem* item);
private:
    std::unique_ptr<QGraphicsScene> graphicsScene_;
};

#endif // GRAPHICS_H
