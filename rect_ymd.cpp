#include "rect_ymd.h"

rect_ymd::rect_ymd(QRect *rect,int y,int m,int d) {

    this->rect = *rect;
    this->y = y;
    this->m = m;
    this->d = d;
}
