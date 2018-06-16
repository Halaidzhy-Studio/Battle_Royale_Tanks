#ifndef QTGRAPHICSSCENEADAPTER_H
#define QTGRAPHICSSCENEADAPTER_H

#include <Graphics/graphicsscene.h>
#include <QGraphicsScene>

class QtGraphicsSceneAdapter : public GraphicsScene, public QGraphicsScene
{
public:
    QtGraphicsSceneAdapter() = default;
    QtGraphicsSceneAdapter(const std::shared_ptr<Logger>&);
    ~QtGraphicsSceneAdapter() = default;
    void setRect(int xp, int yp, int x, int y) override;
    void addItem(GraphicsItem *) override;
    void addWidget(std::shared_ptr<Widget>) override;
    void addPushButtonWidget(std::shared_ptr<PushButtonWidget>) override;
    void addLabelWidget(std::shared_ptr<LabelWidget>) override;
    int width() override;
    int height() override;
    int getActiveKeys();

    QGraphicsScene* sourceScene();

private:
    std::shared_ptr<Logger> logger_;
    int keys_;
    void loggerPrintWrapper(const std::string&);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // QTGRAPHICSSCENEADAPTER_H
