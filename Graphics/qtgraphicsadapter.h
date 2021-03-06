#ifndef QTGRAPHICSADAPTER_H
#define QTGRAPHICSADAPTER_H

#include <Graphics/graphics.h>
#include <QGraphicsScene>
#include <QGraphicsView>

class QtGraphicsAdapter : public Graphics
{
public:
    QtGraphicsAdapter() = default;
    QtGraphicsAdapter(const std::shared_ptr<Logger>&);
    ~QtGraphicsAdapter() = default;
    void setSceneRect(int xp, int yp, int x, int y) override;
    void addItem(GraphicsItem *item) override;
    void setControlable(GraphicsItem *item) override;
    void setViewParent(std::shared_ptr<Widget> parent) override;
    void addWidget(std::shared_ptr<Widget> widget) override;
    void centerViewOn(int x, int y) override;
    void addPushButtonWidget(std::shared_ptr<PushButtonWidget>) override;
    void addLabelWidget(std::shared_ptr<LabelWidget>) override;
private:
    QGraphicsScene* scene_;
    QGraphicsView* view_;
    std::shared_ptr<Logger> logger_;
};

#endif // QTGRAPHICSADAPTER_H
