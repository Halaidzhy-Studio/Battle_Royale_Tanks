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
};

#endif // GAMEWINDOW_H
