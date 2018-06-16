#include "playerhud.h"
#include <Graphics/qtlabeladapter.h>


PlayerHUD::PlayerHUD(const std::shared_ptr<GameData> &data,
                     const std::shared_ptr<Logger> &logger) : logger_(logger)
{
    info_ = data->getHudInfo();
}

void PlayerHUD::update()
{
    if (bodyLogic_)
        hpCount_->setText(std::to_string(bodyLogic_->hp()));
    else
        loggerPrintWrapper("Can't update HPCount widget, LogicBodyComponent is null");

    if (turretLogic_)
        bulletTime_->setText(std::to_string(turretLogic_->bulletRechargeTime()));
    else
        loggerPrintWrapper("Can't update BulletTime widget, LogicTurretComponent is null");

    if (circleLogic_)
        circleTime_->setText(std::to_string(circleLogic_->circleToMoveTime()));
    else
        loggerPrintWrapper("Can't update CircleTime widget, LogicCircleComponent is null");
}

void PlayerHUD::setViewField(std::shared_ptr<Widget> widget)
{
    viewWidget_ = widget;
    initInterface();
}

void PlayerHUD::addHudToViewField()
{
    hpImage_->setParentWidget(viewWidget_);
    hpCount_->setParentWidget(viewWidget_);
    bulletImage_->setParentWidget(viewWidget_);
    bulletTime_->setParentWidget(viewWidget_);
    circleImage_->setParentWidget(viewWidget_);
    circleTime_->setParentWidget(viewWidget_);
}

void PlayerHUD::setBodyLogic(const std::shared_ptr<LogicBodyComponent> &bodyLogic)
{
    bodyLogic_ = bodyLogic;
}

void PlayerHUD::setTurretLogic(const std::shared_ptr<LogicTurretComponent> &turretLogic)
{
    turretLogic_ = turretLogic;
}

void PlayerHUD::setCircleLogic(const std::shared_ptr<LogicCircleComponent> &circleLogic)
{
    circleLogic_ = circleLogic;
}



void PlayerHUD::initInterface()
{
    hpImage_ = create(viewWidget_->getH()/info_.padding,
                      viewWidget_->getH() - info_.hp_image_h - viewWidget_->getH()/info_.padding,
                      info_.hp_image_w, info_.hp_image_h, info_.hp_image_path);

    hpCount_=  create(2*viewWidget_->getH()/info_.padding + info_.hp_image_w,
                      viewWidget_->getH() - info_.hp_image_h -
                      viewWidget_->getH()/info_.padding,
                      info_.hp_count_w, info_.hp_count_h, info_.hp_count_value);

    hpCount_->setTextSize(info_.hp_count_text_size);

    bulletImage_ = create(viewWidget_->getH()/info_.padding,
                          viewWidget_->getH() - info_.hp_image_h - info_.bullet_image_h -
                          2*viewWidget_->getH()/info_.padding,
                          info_.bullet_image_w, info_.bullet_image_h, info_.bullet_image_path);

    bulletTime_ = create(2*viewWidget_->getH()/info_.padding + info_.bullet_image_w,
                         viewWidget_->getH() - info_.hp_image_h - info_.bullet_image_h -
                         2*viewWidget_->getH()/info_.padding,
                         info_.bullet_time_w, info_.bullet_time_h, info_.bullet_time_value);

    bulletTime_->setTextSize(info_.bullet_time_text_size);

    circleImage_ = create(viewWidget_->getH()/info_.padding,
                          viewWidget_->getH() - info_.hp_image_h -
                          info_.bullet_image_h - info_.circle_image_h -
                          3*viewWidget_->getH()/info_.padding,
                          info_.circle_image_w, info_.circle_image_h, info_.circle_image_path);

    circleTime_ = create(2*viewWidget_->getH()/info_.padding + info_.circle_image_w,
                         viewWidget_->getH() - info_.hp_image_h -
                         info_.bullet_image_h - info_.circle_image_h -
                         3*viewWidget_->getH()/info_.padding,
                         info_.circle_time_w, info_.circle_time_h, info_.circle_time_value);

    circleTime_->setTextSize(info_.circle_time_text_size);

}

std::shared_ptr<LabelWidget> PlayerHUD::create(int x, int y, int w, int h, const std::string &path)
{
    std::shared_ptr<LabelWidget> label = std::make_shared<QtLabelAdapter>(logger_);
    label->setGeometry(x, y, w, h);
    label->setTexture(w, h, path);
    return label;
}

std::shared_ptr<LabelWidget> PlayerHUD::create(int x, int y, int w, int h, int value)
{
    std::shared_ptr<LabelWidget> label = std::make_shared<QtLabelAdapter>(logger_);
    label->setGeometry(x, y, w, h);
    label->setText(std::to_string(value));
    return label;
}

void PlayerHUD::loggerPrintWrapper(const std::string &str)
{
    logger_->printLog(str, "[HUD]");
}
