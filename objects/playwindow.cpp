#include "playwindow.h"
#include <Graphics/qtwidget.h>
#include <Graphics/qtpushbuttonadapter.h>
#include <Graphics/qtlabeladapter.h>
#include <QDesktopWidget>
#include <QApplication>
#include <QTimer>

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


void PlayWindow::initPlayerHud(const std::shared_ptr<PlayerHUD> &hud)
{
    hud->setViewField(widget_);
    hud->addHudToViewField();
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
}

void PlayWindow::showWinState()
{
    winLabel_ = std::make_shared<QtLabelAdapter>(logger_);
    winLabel_->setGeometry(
                widget_->getW()/2 - info_.winlabel_w/2,
                widget_->getH()/2 - info_.winlabel_h/2,
                info_.winlabel_w,
                info_.winlabel_h
    );
    winLabel_->setText(info_.winlabel_txt);
    winLabel_->setTextSize(info_.winlabel_txt_size);
    winLabel_->setParentWidget(widget_);
    winLabel_->show();
    QTimer::singleShot(SECOND*info_.state_label_time, this, &PlayWindow::exit);
}

void PlayWindow::showLoseState()
{
    loseLabel_ = std::make_shared<QtLabelAdapter>(logger_);
    loseLabel_->setGeometry(
                widget_->getW()/2 - info_.loselabel_w/2,
                widget_->getH()/2 - info_.loselabel_h/2,
                info_.loselabel_w,
                info_.loselabel_h
    );
    loseLabel_->setText(info_.loselabel_txt);
    loseLabel_->setTextSize(info_.loselabel_txt_size);
    loseLabel_->setParentWidget(widget_);
    loseLabel_->show();
    QTimer::singleShot(SECOND*info_.state_label_time, this, &PlayWindow::exit);
}

void PlayWindow::exit()
{
    widget_->close();
    emit exitSignal();
}
