#ifndef MULTIPLAYERMENUINFOSTRUCT_H
#define MULTIPLAYERMENUINFOSTRUCT_H
#include <string>

struct MultiplayerMenuInfo
{
    int width;
    int height;
    int btn_padding;
    int back_btn_w ;
    int back_btn_h_k ;
    int start_btn_w ;
    int start_btn_h_k ;
    int txt_label_w;
    int txt_label_h_k ;
    int prevt_btn_w ;
    int prevt_btn_h_k ;
    int nextt_btn_w ;
    int nextt_btn_h_k ;

    std::string color;

};

#endif // MULTIPLAYERMENUINFOSTRUCT_H
