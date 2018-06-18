#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <string>

struct GameWindowInfo
{
    int btn_padding;
    int back_btn_width;
    int back_btn_height;
    bool is_full_screen;
    std::string back_btn_txt;
    int width;
    int height;

    int winlabel_w;
    int winlabel_h;
    std::string winlabel_txt;
    int winlabel_txt_size;

    int loselabel_w;
    int loselabel_h;
    std::string loselabel_txt;
    int loselabel_txt_size;

    int state_label_time;

};

#endif // GAMEWINDOW_H
