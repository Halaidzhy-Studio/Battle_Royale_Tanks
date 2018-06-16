#ifndef MENUWINDOWINFOSTRUCT_H
#define MENUWINDOWINFOSTRUCT_H
#include <string>
#include "singleplayermenuinfostruct.h"
#include "multiplayermenuinfostruct.h"

struct MenuWindowInfo {
    int width;
    int height;
    int btn_part_size;
    int btn_w_k;
    int btn_h_k;

    std::string color;
};

#endif // MENUWINDOWINFOSTRUCT_H
