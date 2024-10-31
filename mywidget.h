#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include<QSystemTrayIcon>
#include"year_month_day.h"
// #include "widget.h"
#include "y_m.h"
#include<QPainter>
#include<QMouseEvent>
#include "updateanddelete.h"
#include<QDebug>
#include"rect_ymd.h"
#include "today_todolist.h"

// class Today_TodoList;
QT_BEGIN_NAMESPACE
namespace Ui {
    class MyWidget;
}
QT_END_NAMESPACE



class MyWidget : public QWidget
{
    Q_OBJECT
public:
    QObject *myself;
    QList<QString> strList;
    QList<rect_ymd*> rect_list;
    QList<rect_ymd*> rect_all_list;
    // explicit MyWidget(QWidget *parent = nullptr);
    MyWidget(QWidget *parent);  //,int year = 2024
    ~MyWidget();
    void init(MyWidget *m);// = delete
    // void paintEvent(QPaintEvent *event);
    void paintEvent2(int y,int m,int d);
    // void mousePressEvent(QMouseEvent *event);
    void setupUI(){

        // this->setupUi();

        //把父对象置空
        // this->setParent(nullptr);

        // 清空现有布局//清空现有布局
        // while (this->layout()) {
        //     QLayoutItem* item = this->layout()->takeAt(0);
        //     delete item;
        // }
        // 垂直布局

        vlayout = new QVBoxLayout(this);

        // QMenu *file_menu = new QMenu(this);

        QMenuBar *menuBar = new QMenuBar(this);
        QHBoxLayout *layout1 = new QHBoxLayout(this);
        layout1 -> setMenuBar(menuBar);



        // 创建一个文件菜单
        QMenu *fileMenu = menuBar->addMenu(tr("&日历功能"));

        // 创建打开动作，并添加到文件菜单
        QAction *yAction = new QAction(tr("&输入年份显示该年日历"), this);
        fileMenu->addAction(yAction);
        connect(yAction, &QAction::triggered, this, &MyWidget::query_year);
        // 创建保存动作，并添加到文件菜单
        QAction *ymAction = new QAction(tr("&输入年月显示该月日历"), this);
        fileMenu->addAction(ymAction);
        connect(ymAction, &QAction::triggered, this, &MyWidget::query_year_month);
        // 创建保存动作，并添加到文件菜单
        QAction *ymdAction = new QAction(tr("&输入年月日显示该日星期几"), this);
        fileMenu->addAction(ymdAction);
        connect(ymdAction, &QAction::triggered, this, &MyWidget::query_year_month_day);

        QAction *ymdSumAction = new QAction(tr("&输入年月日距离今天相隔多少"), this);
        fileMenu->addAction(ymdSumAction);
        connect(ymdSumAction, &QAction::triggered, this, &MyWidget::query_year_month_day_sum);//query_year_month_day_sum


        QAction *ymdFestivalAction = new QAction(tr("&输入年月日是否公历节日"), this);
        fileMenu->addAction(ymdFestivalAction);
        connect(ymdFestivalAction, &QAction::triggered, this, &MyWidget::query_year_month_day_festival);//query_year_month_day_festival
        // 添加分隔线
        fileMenu->addSeparator();

        // 创建退出动作，并添加到文件菜单
        QAction *exitAction = new QAction(tr("&退出"), this);
        fileMenu->addAction(exitAction);
        // 连接退出动作的信号槽
        connect(exitAction, &QAction::triggered, this, &MyWidget::close);



        QHBoxLayout *layout3 = new QHBoxLayout(this);//添加选定年份标签的水平布局

        // QWidget::setLayout(nullptr);//设置本组件的布局为空布局

        // 移除布局上所有的小插件
        // if (vlayout||layout||layout2||layout3||layout4) {
        //     vlayout->removeWidget(this);
        //     layout->removeWidget(this);
        //     layout2->removeWidget(this);
        //     layout3->removeWidget(this);
        //     layout4->removeWidget(this);
        // }









        //以下显示查询年份文本框和按钮
        layout_y = new QHBoxLayout(this);//添加第一组文本框和按钮的水平布局
        vlayout->addLayout(layout_y,1);
        // QHBoxLayout *layout4 = new QHBoxLayout(this);//添加空水平布局（占位）
        // vlayout->addLayout(layout4,10);
        // 文本输入框
        lineEdit = new QLineEdit(this);
        // 按钮
        QPushButton *button1 = new QPushButton("确定", this);
        connect(button1, &QPushButton::clicked, this, &MyWidget::query_year_calcu);
        layout_y->addWidget(lineEdit);
        layout_y->addWidget(button1);


        //以下显示查询年月文本框和按钮
        layout_ym = new QHBoxLayout(this);//添加第一组文本框和按钮的水平布局
        // 文本输入框
        lineEdit1 = new QLineEdit(this);
        QLabel *y_label = new QLabel(this);
        y_label->setText("年");
        lineEdit2 = new QLineEdit(this);
        QLabel *m_label = new QLabel(this);
        m_label->setText("月");
        // 按钮
        QPushButton *button2 = new QPushButton("确定", this);
        connect(button2, &QPushButton::clicked, this, &MyWidget::query_year_month_calcu);
        layout_ym->addWidget(lineEdit1);
        layout_ym->addWidget(y_label);
        layout_ym->addWidget(lineEdit2);
        layout_ym->addWidget(m_label);
        layout_ym->addWidget(button2);





        //以下显示查询年月日文本框和按钮
        layout_ymd = new QHBoxLayout(this);//添加第二组文本框和按钮的水平布局

        // QHBoxLayout *layout4 = new QHBoxLayout(this);//添加空水平布局（占位）

        // 文本输入框
        lineEdit11 = new QLineEdit(this);
        QLabel *y_label2 = new QLabel(this);
        y_label2->setText("年");
        lineEdit22 = new QLineEdit(this);
        QLabel *m_label2 = new QLabel(this);
        m_label2->setText("月");
        lineEdit33 = new QLineEdit(this);
        QLabel *d_label2 = new QLabel(this);
        d_label2->setText("日");
        // 按钮
        QPushButton *button3 = new QPushButton("确定", this);
        connect(button3, &QPushButton::clicked, this, &MyWidget::query_year_month_day_calcu);
        layout_ymd->addWidget(lineEdit11);
        layout_ymd->addWidget(y_label2);
        layout_ymd->addWidget(lineEdit22);
        layout_ymd->addWidget(m_label2);
        layout_ymd->addWidget(lineEdit33);
        layout_ymd->addWidget(d_label2);
        layout_ymd->addWidget(button3);



        layout_ymd_sum = new QHBoxLayout(this);
        // 文本输入框
        lineEdit112 = new QLineEdit(this);
        QLabel *y_label22 = new QLabel(this);
        y_label22->setText("年");
        lineEdit222 = new QLineEdit(this);
        QLabel *m_label22 = new QLabel(this);
        m_label22->setText("月");
        lineEdit332 = new QLineEdit(this);
        QLabel *d_label22 = new QLabel(this);
        d_label22->setText("日");
        // 按钮
        QPushButton *button4 = new QPushButton("确定", this);
        connect(button4, &QPushButton::clicked, this, &MyWidget::query_year_month_day_sum_calcu);
        layout_ymd_sum->addWidget(lineEdit112);
        layout_ymd_sum->addWidget(y_label22);
        layout_ymd_sum->addWidget(lineEdit222);
        layout_ymd_sum->addWidget(m_label22);
        layout_ymd_sum->addWidget(lineEdit332);
        layout_ymd_sum->addWidget(d_label22);
        layout_ymd_sum->addWidget(button4);


        layout_ymd_festival = new QHBoxLayout(this);//添加第二组文本框和按钮的水平布局

        // 文本输入框
        lineEdit113 = new QLineEdit(this);
        QLabel *y_label23 = new QLabel(this);
        y_label23->setText("年");
        lineEdit223 = new QLineEdit(this);
        QLabel *m_label23 = new QLabel(this);
        m_label23->setText("月");
        lineEdit333 = new QLineEdit(this);
        QLabel *d_label23 = new QLabel(this);
        d_label2->setText("日");
        // 按钮
        QPushButton *button5 = new QPushButton("确定", this);
        connect(button5, &QPushButton::clicked, this, &MyWidget::query_year_month_day_festival_calcu);
        layout_ymd_festival->addWidget(lineEdit113);
        layout_ymd_festival->addWidget(y_label23);
        layout_ymd_festival->addWidget(lineEdit223);
        layout_ymd_festival->addWidget(m_label23);
        layout_ymd_festival->addWidget(lineEdit333);
        layout_ymd_festival->addWidget(d_label23);
        layout_ymd_festival->addWidget(button5);



        vlayout -> addLayout(layout1,1);//添加放置菜单的布局
        vlayout->addLayout(layout_y,1);//添加放置查询年份的框和按钮的布局
        vlayout->addLayout(layout_ym,1);//添加放置查询年月的框和按钮的布局
        vlayout->addLayout(layout_ymd,1);//添加放置查询年月日的框和按钮的布局
        vlayout->addLayout(layout_ymd_sum,1);//添加放置根据年月日查询总天数的框和按钮的布局
        vlayout->addLayout(layout_ymd_festival,1);//添加放置根据年月日查询是否公历节日的框和按钮的布局
        //隐藏查询按钮和输入文本框
        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

        qlabel = new QLabel(this);
        qlabel->setText("2024年");
        // 创建字体对象
        QFont font;
        // 将字体设置为粗体
        font.setBold(true);
        // 设置字体大小
        font.setPointSize(20);  // 设置字体大小为16像素

        // 将字体应用于标签
        qlabel->setFont(font);
        layout3->addWidget(qlabel);
        vlayout->addLayout(layout3,1);//添加放置年份/年月的标签

        QHBoxLayout *layout4 = new QHBoxLayout(this);//添加空水平布局（占位）
        vlayout->addLayout(layout4,45);







        // 设置布局
        setLayout(vlayout);



    }

    void query_year() {

        displayLayoutContents(layout_y);
        // 弹出消息框显示输入的文本
        // QMessageBox::information(this, "inputValue", "The value is" + QString((char) calculateYMDWhichWeekday(2024,1,1)));


    }
    void query_year_month() {
        displayLayoutContents(layout_ym);
        // vlayout->addLayout(layout4,10);

    }

    void query_year_month_day() {
        displayLayoutContents(layout_ymd);
        // vlayout->addLayout(vlayout,10);

    }

    void query_year_month_day_sum() {
        displayLayoutContents(layout_ymd_sum);
        // vlayout->addLayout(vlayout,10);

    }
    void query_year_month_day_festival(){
        displayLayoutContents(layout_ymd_festival);
    }
    void hideLayoutContents(QLayout *layout) {
        for (int i = 0; i < layout->count(); i++) {
            QLayoutItem *item = layout->itemAt(i);
            if (item->widget()) {
                item->widget()->setVisible(false);
            } else if (item->layout()) {
                hideLayoutContents(item->layout());
            }
        }
    }
    void displayLayoutContents(QLayout *layout) {
        for (int i = 0; i < layout->count(); i++) {
            QLayoutItem *item = layout->itemAt(i);
            if (item->widget()) {
                item->widget()->setVisible(true);
            } else if (item->layout()) {
                displayLayoutContents(item->layout());
            }
        }
    }
private slots:
    void query_year_calcu(){
        // 获取文本输入框的值
        QString inputValue = lineEdit->text();
        ymd.currentYear = (int) inputValue.toInt();
        if(ymd.currentYear<1940||ymd.currentYear>2040){
            QMessageBox::information(this, "提示", "您输入的年份不合法请输入（1940-2040）");
        }
        else{
            qlabel->setText(inputValue+"年");
            this->repaint();
            update();
        }
        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

    }
    void query_year_month_calcu(){
        QString inputValue1 = lineEdit1->text();
        QString inputValue2 = lineEdit2->text();
        // y_m *ym = new y_m(nullptr);
        int year = inputValue1.toInt();
        int month = inputValue2.toInt();
        y_m *ym = new y_m(year, month);
        ym->yy = year;
        ym->mm = month;
        ym->show();
        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

    }
    void query_year_month_day_calcu(){
        // 获取文本输入框的值
        QString inputValue1 = lineEdit11->text();
        QString inputValue2 = lineEdit22->text();
        QString inputValue3 = lineEdit33->text();
        int year = inputValue1.toInt();
        int month = inputValue2.toInt();
        int day = inputValue3.toInt();
        int weekday = calculateYMDWhichWeekday(year,month,day);
        // 弹出消息框显示输入的文本
        if(weekday==0){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期天");
        }else if(weekday==1){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期一");
        }else if(weekday==2){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期二");
        }else if(weekday==3){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期三");
        }else if(weekday==4){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期四");
        }else if(weekday==5){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期五");
        }else if(weekday==6){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "星期六");
        }


        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

    };
    void query_year_month_day_sum_calcu(){
        // 获取文本输入框的值
        QString inputValue1 = lineEdit112->text();
        QString inputValue2 = lineEdit222->text();
        QString inputValue3 = lineEdit332->text();
        int year = inputValue1.toInt();
        int month = inputValue2.toInt();
        int day = inputValue3.toInt();

        int delta_days = abs(calculateSumDays(year,month,day)-calculateSumDays(ymd.currentYear,ymd.currentMonth,ymd.currentDay));
        QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天距离今天", QString::number(delta_days));

        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

    };

    void query_year_month_day_festival_calcu(){
        // 获取文本输入框的值
        QString inputValue1 = lineEdit113->text();
        QString inputValue2 = lineEdit223->text();
        QString inputValue3 = lineEdit333->text();
        // int year = inputValue1.toInt();
        int month = inputValue2.toInt();
        int day = inputValue3.toInt();
        if(month==1&&day==1){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "元旦节");
        }else if(month==5&&day==1){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "劳动节");
        }else if(month==10&&day==1){
            QMessageBox::information(this, inputValue1+"年"+inputValue2+"月"+inputValue3+"日"+"那一天是", "国庆节");
        }

        hideLayoutContents(layout_y);
        hideLayoutContents(layout_ym);
        hideLayoutContents(layout_ymd);
        hideLayoutContents(layout_ymd_sum);
        hideLayoutContents(layout_ymd_festival);

    }
protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
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
        // year_month_day* ymd = new year_month_day(year);
        // ymd->initialymd();
        QPainter paint(this);
        for(int i=0;i<12;i++){

            // size_t daysOfMonth = array_length(ymd->dayys[i]);
            int daysOfMonth = sumDays(ymd.currentYear,i+1);
            for(int j=0;j<daysOfMonth+7;j++){
                paint.drawPixmap(date_xy[i][j],date_total_img[j]);

            }

            paint.drawPixmap(month_xy[i],month_total_img[i]);
        }
        qDebug()<<QString::number(rect_list.size());
        for(rect_ymd* rect_ymd:rect_list){
            QRect rect = rect_ymd->rect;
            // 将 QRect 对象序列化为字符串
            QString serializedRect = QString::number(rect.x()) + ","
                                     + QString::number(rect.y()) + ","
                                     + QString::number(rect.width()) + ","
                                     + QString::number(rect.height());

            // 输出结果
            // qDebug() << "Serialized QRect:" << serializedRect;
            // 设置画笔和画刷
            // paint.setPen(Qt::black);  // 画笔颜色
            paint.setBrush(QColor(0,255,0,10)); // 画刷颜色
            paint.drawRect(rect);
        }
    }

    void mousePressEvent(QMouseEvent *event) override {
        for(rect_ymd* rect_ymd : rect_list){
            QRect rect = rect_ymd->rect;

            // 检查鼠标点击位置是否在矩形内
            if (rect.contains(event->pos())) {
                // qDebug() << "Rectangle Clicked!";
                choosed_rect_ymd = rect_ymd;
                flag = true;
            }
        }

        // for(QRect rect: rect_all_list){
        //     if (rect.contains(event->pos())&&event->button() == Qt::RightButton) {

        //     }
        // }

        if(flag){
            rect_ymd* rect_ymd = choosed_rect_ymd;
            int y = rect_ymd->y;
            int m = rect_ymd->m;
            int d = rect_ymd->d;
            year_month_day *ymd = new year_month_day();
            UpdateAndDelete *upandd = new UpdateAndDelete(nullptr,ymd,y,m,d);
            upandd->show();
            flag = false;
        }
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override {

        for(rect_ymd* rect_ymd: rect_all_list){
            QRect rect = rect_ymd->rect;
            int y = rect_ymd->y;
            int m = rect_ymd->m;
            int d = rect_ymd->d;
            if (rect.contains(event->pos())&&event->button() == Qt::LeftButton) {
                // int x = event->x();
                // int y = event->y();
                year = y;
                month = m;
                day = d;

                flag2 = true;
            }
        }
        if(flag2){
            QString l = QString::number(year)+"-"+QString::number(month)+"-"+QString::number(day);
            qDebug()<<l;
            Today_TodoList *tt = new Today_TodoList(this, l);
            tt->show();
            flag2 = false;
        }

    }
public:
    rect_ymd *choosed_rect_ymd;
    bool flag;
    bool flag2;
    int year;
    int month;
    int day;
    Ui::MyWidget *my_ui;

    QLineEdit *lineEdit;

    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    // QLineEdit *lineEdit3;
    QLineEdit *lineEdit11;
    QLineEdit *lineEdit22;
    QLineEdit *lineEdit33;

    QLineEdit *lineEdit112;
    QLineEdit *lineEdit222;
    QLineEdit *lineEdit332;

    QLineEdit *lineEdit113;
    QLineEdit *lineEdit223;
    QLineEdit *lineEdit333;
    QPixmap date_total_img[31+7];//日期数字图片总数
    QPixmap month_total_img[12];
    QPoint date_xy[12][31+7];
    QPoint month_xy[12];
    QSystemTrayIcon *_traycion;
    year_month_day ymd;
    QLabel *qlabel;//用来显示当前选定的年份
    QVBoxLayout *vlayout;
    QHBoxLayout *layout_y;
    QHBoxLayout *layout_ym;
    QHBoxLayout *layout_ymd;
    QHBoxLayout *layout_ymd_sum;
    QHBoxLayout *layout_ymd_festival;


signals:

};

#endif // MYWIDGET_H
