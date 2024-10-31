#include "updateanddelete.h"
#include "qpushbutton.h"
#include "ui_updateanddelete.h"
#include "year_month_day.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include<QLabel>
#include<QVBoxLayout>
#include<QTableWidget>
// #include"rect_ymd.h"
UpdateAndDelete::UpdateAndDelete(QWidget *parent,year_month_day *ymd,int choosedYear,int choosedMonth,int choosedDay)
    : QWidget(parent)
    , ui(new Ui::UpdateAndDelete)
{
    this->ymd = ymd;
    ui->setupUi(this);
    vlayout = new QVBoxLayout(this);
    setWindowTitle(QString::number(choosedYear)+"-"+QString::number(choosedMonth)+"-"+QString::number(choosedDay)+"待办事宜");
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
            qDebug() << "Line read: " << line;


            strList<<line;
        }

        // 关闭文件
        file.close();

        qDebug() << "File read successfully.";
    } else {
        qDebug() << "Error opening file!";
        // return 1;
    }
    QLabel *l01 = new QLabel(this);
    l01->setText("日期");
    QLabel *l02 = new QLabel(this);
    l02->setText("序号");
    QLabel *l03 = new QLabel(this);
    l03->setText("内容");
    QLabel *l04 = new QLabel(this);
    l04->setText("操作/修改");
    QLabel *l05 = new QLabel(this);
    l05->setText("操作/删除");
    // QTableView *tableWidget = new QTableView(this);
    // 创建一个水平布局
    QHBoxLayout *layout = new QHBoxLayout;
    // 创建一个表格单元格，并将水平布局设置为单元格的布局
    // QWidget *widget = new QWidget;


    layout->addWidget(l01);
    layout->addWidget(l02);
    layout->addWidget(l03);
    layout->addWidget(l04);
    layout->addWidget(l05);


    vlayout->addLayout(layout,3);
    // 将单元格的QWidget设置为表格的一个单元格
    // tableWidget->setCellView(0, 0, widget);
    int count = 0;
    for(QString str:strList){
        // QHBoxLayout *h_layout = new QHBoxLayout(this);

        QHBoxLayout *layout = new QHBoxLayout;
        QList<QString> ss = str.split(",");

        int year = ss[0].split("-")[0].toInt();
        int month = ss[0].split("-")[1].toInt();
        int day = ss[0].split("-")[2].toInt();
        if(year==choosedYear&&month==choosedMonth&&day==choosedDay){
            count += 1;
            QLabel *l1 = new QLabel(this);
            QLabel *l2 = new QLabel(this);
            QLabel *l3 = new QLabel(this);
            l1->setText(ss[0]);
            l2->setText(QString::number(count));
            l3->setText(ss[2]);

            QPushButton *b_update = new QPushButton(this);
            b_update->setText("修改");
            QPushButton *b_delete = new QPushButton(this);
            b_delete->setText("删除");

            connect(b_update, &QPushButton::clicked, this, [=](){
                updatel(layout,l3,count,year,month,day);
            });
            connect(b_delete, &QPushButton::clicked, this, [=](){
                deletel(count,layout,year,month,day);
            });


            // 创建一个表格单元格，并将水平布局设置为单元格的布局
            // QWidget *widget = new QWidget;

            layout->addWidget(l1);
            layout->addWidget(l2);
            layout->addWidget(l3);
            layout->addWidget(b_update);
            layout->addWidget(b_delete);

            vlayout->addLayout(layout,1);
        }

        // 将单元格的QWidget设置为表格的一个单元格
        // tableWidget->setCellWidget(count, 0, widget);
        // count+=1;
        // h_layout->addWidget(l1);
        // h_layout->addWidget(l2);
        // h_layout->addWidget(l3);
        // h_layout->addWidget(&b_update);
        // h_layout->addWidget(&b_delete);
        // vlayout->addLayout(h_layout);

    }
    // vlayout->addWidget(tableWidget);
    setLayout(vlayout);
    this->repaint();
    this->update();
}

UpdateAndDelete::~UpdateAndDelete()
{
    delete ui;
}
