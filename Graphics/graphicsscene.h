#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H
#include <Graphics/pushbuttonwidget.h>
#include <Graphics/labelwidget.h>
#include <Graphics/graphicsitem.h>

class GraphicsScene {
public:
    virtual ~GraphicsScene() = default;
    virtual void setRect(int xp, int yp, int x, int y) = 0;
    virtual void addItem(GraphicsItem*) = 0;
    virtual void addWidget(std::shared_ptr<Widget>) = 0;
    virtual void addPushButtonWidget(std::shared_ptr<PushButtonWidget>) = 0;
    virtual void addLabelWidget(std::shared_ptr<LabelWidget>) = 0;
    virtual int width() = 0;
    virtual int height() = 0;
    virtual int getActiveKeys() = 0;
};

#endif // GRAPHICSSCENE_H
