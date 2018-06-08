#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <memory>
#include <Graphics/graphicsitem.h>
#include <Graphics/widget.h>

class Graphics
{
public:
    virtual ~Graphics() = default;
    virtual void setSceneRect(int xp, int yp, int x, int y) = 0;
    virtual void addItem(GraphicsItem* item) = 0;
    virtual void setControlable(GraphicsItem* item) = 0;
    virtual void setViewParent(Widget* parent) = 0;
    virtual void addWidget(Widget* widget) = 0;
    virtual void centerViewOn(int x, int y) = 0;
};

#endif // GRAPHICS_H
