#ifndef QTGRAPHICSITEMADAPTER_H
#define QTGRAPHICSITEMADAPTER_H

#include <QGraphicsItem>
#include <Graphics/graphicsitem.h>
#include <Graphics/graphics.h>
#include <QPainter>

class QtGraphicsItemAdapter : public GraphicsItem, public QGraphicsItem
{
public:
    QtGraphicsItemAdapter(const std::shared_ptr<Graphics>&);
    ~QtGraphicsItemAdapter() = default;

private:
    std::shared_ptr<Graphics> graphics_;
    QRectF rectF_;

    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // GraphicsItem interface
    void setPos(Coordinate) override;
    void setRotation(int) override;
    void isControlable(bool) override;
    void setTexture(Texture) override;
    void setRect(int, int, int, int) override;
    void setRect(int, int) override;
    void setControlable() override;
};

#endif // QTGRAPHICSITEMADAPTER_H
