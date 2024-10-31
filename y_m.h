#ifndef Y_M_H
#define Y_M_H

#include <QWidget>

namespace Ui {
class y_m;
}

class y_m : public QWidget
{
    Q_OBJECT

public:
    y_m(int year,int month);
    ~y_m();
    int yy;
    int mm;
    QPixmap date_total_img[31+7];//日期数字图片总数
    QPixmap month_img;
    QPoint date_xy[31+7];
    QPoint month_xy;
    void paintEvent(QPaintEvent *event);
private:
    Ui::y_m *ui;

};

#endif // Y_M_H
