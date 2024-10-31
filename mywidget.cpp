// #include "widget.h"
#include "ui_mywidget.h"
#include "year_month_day.h"
#include <QPainter>
#include "util_calendar.h"
#include "mywidget.h"
// #include<iostream>
#include <QDesktopWidget>
#include <QScreen>
#include <QGuiApplication>
#include <QWidget>
#include<QIcon>
#include<QAction>
#include<QMenu>
#include<QApplication>
#include<QFile>
#include<QDebug>
#include<QString>
#include <QMouseEvent>
#include "rect_ymd.h"
#include<QRect>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    // ,*choosed_rect_ymd(nullptr,1940,1,1)
    ,my_ui(new Ui::MyWidget)
{

    // // 创建一个 QRect 对象（示例中用 new 分配内存，但最好避免使用 new）
    // QRect* rectPointer = new QRect();

    // // 使用成员初始化语法为 choosed_rect_ymd 初始化
    // choosed_rect_ymd = rect_ymd(rectPointer, 1940, 1, 1);

    rect_all_list = {};

    flag = false;
    flag2 = false;
    // 创建一个 QFile 对象
    QFile file("C:\\data.csv");

    // 打开文件，如果文件存在
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // 创建一个 QTextStream 对象，并将其绑定到 QFile
        QTextStream in(&file);

        // 读取文件内容
        while (!in.atEnd()) {
            QString line = in.readLine();
            // 在这里你可以对每一行的数据进行处理
            // qDebug() << "Line read: " << line;
            strList << line;
        }

        // 关闭文件
        file.close();

        qDebug() << "File read successfully.";
    } else {
        qDebug() << "Error opening file!";
        // return 1;
    }



    //把父对象置空
    this->setParent(nullptr);

    setupUI();
    // my_ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//去掉窗口边框
    // setAttribute(Qt::WA_TranslucentBackground);
   QDesktopWidget *desktop = QApplication::desktop();
     //QScreen* desktop= QGuiApplication:primaryScreen();
   setFixedSize(desktop->width(),desktop->height());

     // 获取屏幕的宽度和高度
    // int screenWidth = screen()->geometry().width();
    // int screenHeight = screen()->geometry().height();

     // 设置窗口的固定大小为屏幕的宽度和高度
    // window()->setFixedSize(screenWidth, screenHeight);





    setWindowTitle("calendar");
    //初始化月份图片及其位置
    for(int i=0;i<12;i++){
        QString month_img_name = QString(":new/images/m%1.png").arg(i+1);
        month_total_img[i] = QPixmap(month_img_name);
    }
    for(int i=0;i<12;i++){
        if(i<6){
            month_xy[i].rx() = 12.5+200*i;
            month_xy[i].ry() = 112.5+0+50;
        }else{
            month_xy[i].rx() = 12.5+200*i-1200;
            month_xy[i].ry() = 112.5+500+50;
        }
    }
    //初始化日期数字图片及其位置

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
    // year_month_day* ymd = new year_month_day(year);

    // for(int i=0;i<12;i++){
    //     ymd.months[i] = i+1;
    // }
    // ymd.input_year = 2024;
    //初始化日期数字图片的位置
    for(int i=0;i<12;i++){

        // size_t daysOfMonth = array_length(ymd->dayys[i]);
        int daysOfMonth = sumDays(ymd.currentYear,i+1);//计算当前月份一共有多少天
        int offset = calculateYMDWhichWeekday(ymd.currentYear,i+1,1);
        if(i<6){
            for(int j=0;j<daysOfMonth+7;j++){
                if(j<7){
                    date_xy[i][j].rx() = 12.5+i*200+(j%7)*25;
                    date_xy[i][j].ry() = 212.5+((int)(j/7))*50;
                }else{

                    date_xy[i][j].rx() = 12.5+i*200+((j+offset)%7)*25;
                    date_xy[i][j].ry() = 212.5+((int)((j+offset)/7))*50;
                }

            }
        }else{
            for(int j=0;j<daysOfMonth+7;j++){
                if(j<7){
                    date_xy[i][j].rx() = 12.5+i*200+(j%7)*25-1200;
                    date_xy[i][j].ry() = 712.5+((int)(j/7))*50;
                }else{
                    // int offset = calculateYMDWhichWeekday(2024,i+1,1);
                    date_xy[i][j].rx() = 12.5+i*200+((j+offset)%7)*25-1200;
                    date_xy[i][j].ry() = 712.5+((int)((j+offset)/7))*50;
                }

            }
        }
    }




    for(QString ss:strList){//.mid(1, strList.size()-1)
        QString y_m_d = ss.split(",")[0];
        int y = y_m_d.split("-")[0].toInt();
        int m = y_m_d.split("-")[1].toInt();
        int d = y_m_d.split("-")[2].toInt();
        qDebug()<<y_m_d;
        this->paintEvent2(y,m,d);
    }



    //设置托盘菜单信息
    _traycion=new QSystemTrayIcon(QIcon(":/new/images/Love.ICO"));
    _traycion->setToolTip("万年历");
    //设置托盘菜单
    QMenu *menu=new QMenu;
    QAction *action=new QAction("关闭程序");
    action->setIcon(QIcon(":/new/images/CloseAction.png"));
    menu->addAction(action);
    //把菜单添加到系统托盘
    _traycion->setContextMenu(menu);
    _traycion->show();
    //信号处理，谁发送什么信号，谁怎么处理接受，
    connect(action,&QAction::triggered,this,
            [=]()
            {
                this->close();
            }
            );

    my_ui->setupUi(this);

}
MyWidget::~MyWidget()
{
    delete my_ui;
}

void MyWidget::init(MyWidget *m)
{
    myself = m;
}
// void MyWidget::paintEvent(QPaintEvent *event)
// {


//     //初始化日期数字图片的位置
//     for(int i=0;i<12;i++){

//         // size_t daysOfMonth = array_length(ymd->dayys[i]);
//         int daysOfMonth = sumDays(ymd.currentYear,i+1);//计算当前月份一共有多少天
//         int offset = calculateYMDWhichWeekday(ymd.currentYear,i+1,1);
//         if(i<6){
//             for(int j=0;j<daysOfMonth+7;j++){
//                 if(j<7){
//                     date_xy[i][j].rx() = 12.5+i*200+(j%7)*25;
//                     date_xy[i][j].ry() = 212.5+((int)(j/7))*50;
//                 }else{

//                     date_xy[i][j].rx() = 12.5+i*200+((j+offset)%7)*25;
//                     date_xy[i][j].ry() = 212.5+((int)((j+offset)/7))*50;
//                 }

//             }
//         }else{
//             for(int j=0;j<daysOfMonth+7;j++){
//                 if(j<7){
//                     date_xy[i][j].rx() = 12.5+i*200+(j%7)*25-1200;
//                     date_xy[i][j].ry() = 712.5+((int)(j/7))*50;
//                 }else{
//                     // int offset = calculateYMDWhichWeekday(2024,i+1,1);
//                     date_xy[i][j].rx() = 12.5+i*200+((j+offset)%7)*25-1200;
//                     date_xy[i][j].ry() = 712.5+((int)((j+offset)/7))*50;
//                 }

//             }
//         }
//     }
//     // year_month_day* ymd = new year_month_day(year);
//     // ymd->initialymd();
//     QPainter paint(this);
//     for(int i=0;i<12;i++){

//         // size_t daysOfMonth = array_length(ymd->dayys[i]);
//         int daysOfMonth = sumDays(ymd.currentYear,i+1);
//         for(int j=0;j<daysOfMonth+7;j++){
//             paint.drawPixmap(date_xy[i][j],date_total_img[j]);

//         }

//         paint.drawPixmap(month_xy[i],month_total_img[i]);
//     }
//     // QPoint p = QPoint();
//     // p.rx() = 100;
//     // p.ry() = 100;
//     // paint.drawPixmap(p,date_total_img[0]);
// }

void MyWidget::paintEvent2(int y,int m,int d)
{



    for(int i=0;i<12;i++){

        // size_t daysOfMonth = array_length(ymd->dayys[i]);
        int daysOfMonth = sumDays(ymd.currentYear,i+1);
        for(int j=0;j<daysOfMonth+7;j++){

            QRect rect2(date_xy[i][j].x()-3,date_xy[i][j].y()-3,25,25); // 左上角坐标(50, 50)，宽度100，高度100
            rect_ymd *rymd2 = new rect_ymd(&rect2,ymd.currentYear,i+1,j-6);
            rect_all_list.append(rymd2);
            // paint.drawPixmap(date_xy[i][j],date_total_img[j]);
            if(ymd.currentYear==y&&(i+1)==m&&(j-6)==d){

                qDebug() << "那一天有待办事宜。" ;


                // 绘制方框
                QRect rect(date_xy[i][j].x()-3,date_xy[i][j].y()-3,25,25); // 左上角坐标(50, 50)，宽度100，高度100
                rect_ymd *rymd = new rect_ymd(&rect,y,m,d);
                rect_list.append(rymd);
                // rect_list<<rect;
            }


        }

        // paint.drawPixmap(month_xy[i],month_total_img[i]);
    }
    // this->update();

}

// void MyWidget::mousePressEvent(QMouseEvent *event) {
//     for(QRect rect: rect_list){
//         // 检查鼠标点击位置是否在矩形内
//         if (rect.contains(event->pos())) {
//             qDebug() << "Rectangle Clicked!";

//             year_month_day *ymd = new year_month_day();
//             UpdateAndDelete *upandd = new UpdateAndDelete(nullptr,ymd);
//             upandd->show();
//         } else {
//             qDebug() << "Not Clicked!";
//         }
//     }
// }


