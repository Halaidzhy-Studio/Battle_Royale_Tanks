#include "playerhud.h"
#include <Graphics/qtlabeladapter.h>


PlayerHUD::PlayerHUD(const std::shared_ptr<GameData> &data,
                     const std::shared_ptr<Logger> &logger) : logger_(logger)
{
    info_ = data->getHudInfo();
}

void PlayerHUD::setViewField(std::shared_ptr<Widget> widget)
{
    viewWidget_ = widget;
}

void PlayerHUD::initInterface()
{
    hpImage_ = create(info_.hp_image_x, info_.hp_image_y,
                      info_.hp_image_w, info_.hp_image_h, info_.hp_image_path);
    hpCount_=  create(info_.hp_count_x, info_.hp_count_y,
                      info_.hp_count_w, info_.hp_count_h, info_.hp_count_value);
    bulletImage_ = create(info_.bullet_image_x, info_.bullet_image_y,
                          info_.bullet_image_w, info_.bullet_image_h, info_.bullet_image_path);
    bulletTime_ = create(info_.bullet_time_x, info_.bullet_time_y,
                         info_.bullet_time_w, info_.bullet_time_h, info_.bullet_time_value);

    circleImage_ = create(info_.circle_image_x, info_.circle_image_y,
                          info_.circle_image_w, info_.circle_image_h, info_.circle_image_path);

    circleTime_ = create(info_.circle_time_x, info_.circle_time_y,
                          info_.circle_time_w, info_.circle_time_h, info_.circle_time_value);

}

std::shared_ptr<LabelWidget> PlayerHUD::create(int x, int y, int w, int h, const std::string &path)
{
    std::shared_ptr<LabelWidget> label = std::make_shared<QtLabelAdapter>(logger_);
    label->setGeometry(x, y, w, h);
    label->setTexture(w, h, path);
    return label;
}

std::shared_ptr<LabelWidget> PlayerHUD::create(int x, int y, int h, int w, int value)
{
    std::shared_ptr<LabelWidget> label = std::make_shared<QtLabelAdapter>(logger_);
    label->setGeometry(x, y, w, h);
    label->setText(std::to_string(value));
    return label;
}
