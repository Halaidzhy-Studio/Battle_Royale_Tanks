#include "qtgraphicssceneadapter.h"
#include <Graphics/qtwidget.h>
#include <Graphics/qtpushbuttonadapter.h>
#include <Graphics/qtlabeladapter.h>
#include <Graphics/qtgraphicsitemadapter.h>
#include <engine.h>

QtGraphicsSceneAdapter::QtGraphicsSceneAdapter(const std::shared_ptr<Logger> &logger) :
    logger_(logger)
{
}


void QtGraphicsSceneAdapter::setRect(int xp, int yp, int x, int y)
{
    this->setSceneRect(xp, yp, x, y);
}

void QtGraphicsSceneAdapter::addItem(GraphicsItem *item)
{
    auto qtItem = dynamic_cast<QtGraphicsItemAdapter*>(item);
    if (qtItem){
        QGraphicsScene::addItem(qtItem);
    }else {
        loggerPrintWrapper("Can't cast GraphicsItem* to QtGraphicsItemAdapter*");
    }
}

void QtGraphicsSceneAdapter::addWidget(std::shared_ptr<Widget> widget)
{
    auto qtWidget = std::dynamic_pointer_cast<QtWidget>(widget);

    if (qtWidget){
        QGraphicsScene::addWidget(qtWidget->getSourceWidget());
    }else {
        loggerPrintWrapper("Can't cast Widget* to QtWidget*");
    }
}

void QtGraphicsSceneAdapter::addPushButtonWidget(std::shared_ptr<PushButtonWidget> pushButton)
{
    auto qtPushButton = std::dynamic_pointer_cast<QtPushButtonAdapter>(pushButton);
    if (qtPushButton){
        QGraphicsScene::addWidget(qtPushButton->getSourceWidget());
    } else {
        loggerPrintWrapper("Can't cast PushButtonWidget* to QtPushButtonAdapter*");
    }
}

void QtGraphicsSceneAdapter::addLabelWidget(std::shared_ptr<LabelWidget> label)
{
    auto qtLabelWidget = std::dynamic_pointer_cast<QtLabelAdapter>(label);
    if (qtLabelWidget){
        QGraphicsScene::addWidget(qtLabelWidget->getSourceWidget());
    }else {
        loggerPrintWrapper("Can't cast LabelWidget* to QtLabelAdapter*");
    }
}

void QtGraphicsSceneAdapter::loggerPrintWrapper(const std::string &str)
{
    logger_->printLog(str, "[GRAPHICS]");
}


int QtGraphicsSceneAdapter::width()
{
    return QGraphicsScene::width();
}

int QtGraphicsSceneAdapter::height()
{
    return QGraphicsScene::height();
}

int QtGraphicsSceneAdapter::getActiveKeys()
{
    return keys_;
}

QGraphicsScene *QtGraphicsSceneAdapter::sourceScene()
{
    return this;
}

void QtGraphicsSceneAdapter::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ |= static_cast<int>(Engine::Keys::KEY_W); break;
    case Qt::Key_S: keys_ |= static_cast<int>(Engine::Keys::KEY_S); break;
    case Qt::Key_D: keys_ |= static_cast<int>(Engine::Keys::KEY_D); break;
    case Qt::Key_A: keys_ |= static_cast<int>(Engine::Keys::KEY_A); break;
    case Qt::Key_Left: keys_ |= static_cast<int>(Engine::Keys::KEY_LEFT); break;
    case Qt::Key_Right: keys_ |= static_cast<int>(Engine::Keys::KEY_RIGHT); break;
    case Qt::Key_Space: keys_ |= static_cast<int>(Engine::Keys::KEY_SPACE); break;
    default:
        break;
    }
}

void QtGraphicsSceneAdapter::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W: keys_ &= ~static_cast<int>(Engine::Keys::KEY_W); break;
    case Qt::Key_S: keys_ &= ~static_cast<int>(Engine::Keys::KEY_S); break;
    case Qt::Key_D: keys_ &= ~static_cast<int>(Engine::Keys::KEY_D); break;
    case Qt::Key_A: keys_ &= ~static_cast<int>(Engine::Keys::KEY_A); break;
    case Qt::Key_Left: keys_ &= ~static_cast<int>(Engine::Keys::KEY_LEFT); break;
    case Qt::Key_Right: keys_ &= ~static_cast<int>(Engine::Keys::KEY_RIGHT); break;
    case Qt::Key_Space: keys_ &= ~static_cast<int>(Engine::Keys::KEY_SPACE); break;
    default:
        break;
    }
}

