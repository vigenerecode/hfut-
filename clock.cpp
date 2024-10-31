#include "clock.h"
#include "ui_clock.h"
#include "year_month_day.h"
// Clock::Clock(QGraphicsView *parent)
//     : QGraphicsView(parent)
//     , ui(new Ui::Clock);


// Clock::~Clock()
// {
//     delete ui;
// }
Clock::Clock(QWidget *parent) : QWidget(parent)
    , ui(new Ui::Clock)
{

    ui->setupUi(this);
    auto ymd = new year_month_day();
    QString today = QString::number(ymd->currentYear)+"年"+QString::number(ymd->currentMonth)+"月"+QString::number(ymd->currentDay)+"日";
    ui->label->setText(today);
    // 设置窗口属性
    setWindowTitle("模拟时钟");
    setFixedSize(300, 300);

    // 创建定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Clock::updateTime);
    timer->start(1000); // 每秒触发一次

    // 设置字体
    font.setPixelSize(20);

    // 获取当前时间并更新显示
    updateTime();
}
Clock::~Clock(){
    delete ui;
}
