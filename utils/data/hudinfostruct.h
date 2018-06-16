#ifndef HUDINFOSTRUCT_H
#define HUDINFOSTRUCT_H

#include <string>
struct HudInfo{

    int padding;

    int hp_image_w;
    int hp_image_h;
    int hp_image_x;
    int hp_image_y;
    std::string hp_image_path;

    int hp_count_w;
    int hp_count_h;
    int hp_count_x;
    int hp_count_y;
    int hp_count_value;
    int hp_count_text_size;

    int bullet_image_w;
    int bullet_image_h;
    int bullet_image_x;
    int bullet_image_y;
    std::string bullet_image_path;

    int bullet_time_w;
    int bullet_time_h;
    int bullet_time_x;
    int bullet_time_y;
    int bullet_time_value;
    int bullet_time_text_size;

    int circle_image_w;
    int circle_image_h;
    int circle_image_x;
    int circle_image_y;
    std::string circle_image_path;

    int circle_time_w;
    int circle_time_h;
    int circle_time_x;
    int circle_time_y;
    int circle_time_value;
    int circle_time_text_size;
};

#endif // HUDINFOSTRUCT_H
