#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <utils/coordinate.h>
#include <Graphics/texture.h>

class GraphicsItem
{
public:
    virtual ~GraphicsItem() = default;
    virtual void setPos(Coordinate&) = 0;
    virtual void setRotation(int) = 0;
    virtual void isControlable(bool) = 0;
    virtual void setControlable() = 0;
    virtual void setTexture(Texture) = 0;
    virtual void setRect(int, int, int, int) = 0;
};

#endif // GRAPHICSITEM_H
