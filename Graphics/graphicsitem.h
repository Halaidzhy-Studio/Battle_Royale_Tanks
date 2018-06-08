#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <utils/coordinate.h>

class GraphicsItem
{
public:
    virtual ~GraphicsItem() = default;
    virtual void setPos(Coordinate) = 0;
    virtual void setRotation(int) = 0;
    virtual void isControlable(bool) = 0;
    virtual void setControlable() = 0;
    virtual void setTexture(const std::string&) = 0;

    virtual void setIsScalableTexture(bool) = 0;

    // центр координат Item == центру Rect
    virtual void setRect(int, int) = 0;

    // Произвольный центр координат
    virtual void setRect(int, int, int, int) = 0;
    virtual int getActiveKeys() = 0;
    virtual void setParent(GraphicsItem*) = 0;
};

#endif // GRAPHICSITEM_H
