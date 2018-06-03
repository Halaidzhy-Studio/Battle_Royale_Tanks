#ifndef QTGRAPHICSITEMADAPTER_H
#define QTGRAPHICSITEMADAPTER_H

#include <QGraphicsItem>
#include <Graphics/graphicsitem.h>
#include <Graphics/graphics.h>
#include <QPainter>
#include <QKeyEvent>

class QtGraphicsItemAdapter : public GraphicsItem, public QGraphicsItem
{
public:
    QtGraphicsItemAdapter(const std::shared_ptr<Graphics>&);
    ~QtGraphicsItemAdapter() = default;

private:
    std::shared_ptr<Graphics> graphics_;
    QRectF rectF_;
    int keys_;

    enum {
        KEY_W = 0x01,
        KEY_S = 0x02,
        KEY_A = 0x04,
        KEY_D = 0x08,
    };

    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    // GraphicsItem interface
    void setPos(Coordinate) override;
    void setRotation(int) override;
    void isControlable(bool) override;
    void setTexture(Texture) override;
    void setRect(int, int, int, int) override;
    void setRect(int, int) override;
    void setControlable() override;
    int getActiveKeys() override;

};

#endif // QTGRAPHICSITEMADAPTER_H
