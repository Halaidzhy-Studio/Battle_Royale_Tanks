#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <memory>

class Graphics
{
public:
    Graphics();
    ~Graphics();
    void setSceneRect(int xp, int yp, int x, int y);
    void addItem(QGraphicsItem* item);
    void setControlable(QGraphicsItem* item);
    void setViewParent(QWidget* parent);
    void addWidget(QWidget* widget);
    void centerViewOn(int x, int y);
private:
    QGraphicsScene* graphicsScene_;
    QGraphicsView* graphicsView_;
};

#endif // GRAPHICS_H
