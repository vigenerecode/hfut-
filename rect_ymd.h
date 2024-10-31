#ifndef RECT_YMD_H
#define RECT_YMD_H

#include <QWidget>

class rect_ymd
{
    // Q_OBJECT
public:
    rect_ymd(QRect *rect,int y,int m,int d);
    ~rect_ymd(){}
    QRect rect;
    int y;
    int m;
    int d;
};

#endif // RECT_YMD_H
