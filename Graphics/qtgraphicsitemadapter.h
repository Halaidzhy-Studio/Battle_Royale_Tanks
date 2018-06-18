#ifndef QTGRAPHICSITEMADAPTER_H
#define QTGRAPHICSITEMADAPTER_H

#include <QGraphicsItem>
#include <Graphics/graphicsitem.h>
#include <Graphics/graphics.h>
#include <QPainter>
#include <QKeyEvent>
#include <QPixmap>

class QtGraphicsItemAdapter : public GraphicsItem, public QGraphicsItem
{
public:
    QtGraphicsItemAdapter(const std::shared_ptr<Graphics>&,
                          const std::shared_ptr<Logger>& logger);

    virtual ~QtGraphicsItemAdapter() = default;

    // GraphicsItem interface
    void setPos(Coordinate) override;
    void setRotation(int) override;
    void isControlable(bool) override;
    void setTexture(const std::string&) override;
    void setRect(int, int) override;
    void setRect(int, int, int, int) override;
    void setControlable() override;
    int getActiveKeys() override;
    void setParent(GraphicsItem *) override;
    void setIsScalableTexture(bool) override;
    void setOpacity(double) override;
    void close() override;

private:
    std::shared_ptr<Graphics> graphics_;
    std::shared_ptr<Logger> logger_;
    QPixmap pixmap;
    bool isScalableTexture_;
    double opacity_;
    QRectF rectF_;
    int keys_;

protected:
    // QGraphicsItem interface
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // QTGRAPHICSITEMADAPTER_H
