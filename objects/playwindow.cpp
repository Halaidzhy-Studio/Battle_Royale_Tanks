#include "playwindow.h"
#include <Graphics/qtwidget.h>
#include <Graphics/qtpushbuttonadapter.h>
#include <QDesktopWidget>
#include <QApplication>

PlayWindow::PlayWindow(const std::shared_ptr<GameData> &data,
                       const std::shared_ptr<Graphics> &graphics,
                       const std::shared_ptr<Logger> &logger) :
    widget_(std::make_shared<QtWidget>()), graphics_(graphics), logger_(logger)
{
    info_ = data->getGameWindowInfo();
    if (info_.is_full_screen){
        widget_->resize(QApplication::desktop()->size().width(),
                        QApplication::desktop()->size().height());
    } else
        widget_->resize(info_.width, info_.height);
}


void PlayWindow::initPlayerHud(const std::shared_ptr<PlayerHUD> &)
{

}

void PlayWindow::setSize(int w, int h)
{
    widget_->resize(w, h);
}

void PlayWindow::setRenderView(const std::shared_ptr<Graphics> &graphics)
{
    graphics->setViewParent(widget_);
}

void PlayWindow::show()
{
    widget_->show();
}

void PlayWindow::initInterface()
{
    exitBTN_ = std::make_shared<QtPushButtonAdapter>();
    exitBTN_->setGeometry(
                widget_->getW() - info_.back_btn_width - widget_->getW()/info_.btn_padding,
                widget_->getW()/info_.btn_padding, info_.back_btn_width, info_.back_btn_height);

    exitBTN_->setText(info_.back_btn_txt);
    exitBTN_->setCallback([this](){
        exit();
    });

    exitBTN_->setParent(widget_);
    graphics_->addPushButtonWidget(exitBTN_);
}

void PlayWindow::exit()
{
    widget_->close();
    emit exitSignal();
}
