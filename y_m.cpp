#include "y_m.h"
#include "ui_y_m.h"
#include "util_calendar.h"
#include<QPainter>
y_m::y_m(int year,int month)
    : QWidget()
    , ui(new Ui::y_m)
{
     ui->setupUi(this);
    QString qs = QString::number(year)+"年"+QString::number(month)+"月";
    setWindowTitle(qs);

    for(int i=0;i<31+7;i++){


        if(i<7){
            QString date_img_name0 = QString(":new/images/日.png");
            date_total_img[0] = QPixmap(date_img_name0);
            QString date_img_name1 = QString(":new/images/一.png");
            date_total_img[1] = QPixmap(date_img_name1);
            QString date_img_name2 = QString(":new/images/二.png");
            date_total_img[2] = QPixmap(date_img_name2);
            QString date_img_name3 = QString(":new/images/三.png");
            date_total_img[3] = QPixmap(date_img_name3);
            QString date_img_name4 = QString(":new/images/四.png");
            date_total_img[4] = QPixmap(date_img_name4);
            QString date_img_name5 = QString(":new/images/五.png");
            date_total_img[5] = QPixmap(date_img_name5);
            QString date_img_name6 = QString(":new/images/六.png");
            date_total_img[6] = QPixmap(date_img_name6);

        }else{
            QString date_img_name = QString(":new/images/%1.png").arg(i+1-7);
            date_total_img[i] = QPixmap(date_img_name);
        }

    }
    auto size = date_total_img[37].size() * 0.5;
    for(int i=0;i<31+7;i++){
        QPixmap scaledPixmap = date_total_img[i].scaled(size, Qt::KeepAspectRatio);
        date_total_img[i] = scaledPixmap;
    }

    //初始化月份图片

    QString month_img_name = QString(":new/images/m%1.png").arg(month);
    month_img = QPixmap(month_img_name);


    //初始化位置
    int daysOfMonth = sumDays(year,month);//计算当前月份一共有多少天
    int offset = calculateYMDWhichWeekday(year,month,1);

    for(int j=0;j<daysOfMonth+7;j++){
        if(j<7){
            date_xy[j].rx() = 12.5+(j%7)*25;
            date_xy[j].ry() = 212.5+((int)(j/7))*50;
        }else{

            date_xy[j].rx() = 12.5+((j+offset)%7)*25;
            date_xy[j].ry() = 212.5+((int)((j+offset)/7))*50;
        }

    }
    month_xy.rx() = 12.5+0;
    month_xy.ry() = 212.5-120;

}

y_m::~y_m()
{
    delete ui;
}

void y_m::paintEvent(QPaintEvent *event)
{



    QPainter paint(this);
    paint.drawPixmap(month_xy,month_img);
    int daysOfMonth = sumDays(yy,mm);
    for(int j=0;j<daysOfMonth+7;j++){
        paint.drawPixmap(date_xy[j],date_total_img[j]);

    }
}
