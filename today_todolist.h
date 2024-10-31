#ifndef TODAY_TODOLIST_H
#define TODAY_TODOLIST_H
#include "year_month_day.h"
#include "ui_today_todolist.h"
#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
// #include "mywidget.h"

class MyWidget; // 前向声明
namespace Ui {
class Today_TodoList;
}

class Today_TodoList : public QWidget
{
    Q_OBJECT

public:
    Today_TodoList(QWidget *parent ,QString l );
    // Today_TodoList* Toady_TodoList(QString l);
    ~Today_TodoList();
    year_month_day *ymd;
    MyWidget *my_w;
protected:
    void closeEvent(QCloseEvent *event) override {
        // 在这里添加你想要执行的关闭事件逻辑
        // MyWidget *my_w = new MyWidget(nullptr);
        // my_w->show();
        // this->parentWidget()->repaint();
        QWidget::closeEvent(event);
        // this->close();
    }

    void focusOutEvent(QFocusEvent *event) override {
        // 当组件失去焦点时，执行相应的操作
        qDebug() << "Today_Todolist Widget lost focus";

        this->QWidget::close();
        // 调用基类的实现，确保其他事件处理函数得到调用
        QWidget::focusOutEvent(event);

    }



private:
    Ui::Today_TodoList *ui;
    QString ll_today;
private slots:
    void onCloseButtonClick(){
        this->close();
        delete this;

    }
    void onButtonClick2(){
        // label = ;
        QString l_str = ui->label->text();
        // lineEdit = ;
        QString i_str = ui->lineEdit->text();

        QString today = ll_today;


        // setWindowTitle(ll_today);
        ui->label_2->setText(ll_today);

        // 创建一个 QFile 对象
        QFile file("data.csv");

        // 打开文件，如果不存在则创建
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            // if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // 创建一个 QTextStream 对象，并将其绑定到 QFile
            QTextStream out(&file);
            if(ymd->count<2){
                // 写入CSV头部
                // out << "date, Num, todo" << "\n";
                // 写入CSV数据
                out << today<<","<< l_str<<","<< i_str << "\n";


                // 关闭文件
                file.close();

                qDebug() << "Content written successfully.";
            }else{
                // 写入CSV数据
                out << today<<","<< l_str<<","<< i_str << "\n";


                // 关闭文件
                file.close();

                qDebug() << "Content written successfully.";
            }
            // }else{
            //     qDebug() << "Could not open or create file.";
            // }
        } else {
            qDebug() << "Error opening file!";
            // return 1;
        }


        // int count = 2;
        // delete ui->label;
        // delete ui->lineEdit;
        // delete ui->pushButton;
        // ui->label = new QLabel(this);
        ymd->count++;
        ui->label->setText(QString::number(ymd->count));
        ui->lineEdit->clear();
    }
    void onButtonClick(){
        // ui->tableWidget->;
        // label = ;
        QString l_str = ui->label->text();
        // lineEdit = ;
        QString i_str = ui->lineEdit->text();

        QString today = QString::number(ymd->currentYear)+"-"+QString::number(ymd->currentMonth)+"-"+QString::number(ymd->currentDay);


        // 创建一个 QFile 对象
        QFile file("data.csv");

        // 打开文件，如果不存在则创建
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            // 创建一个 QTextStream 对象，并将其绑定到 QFile
            QTextStream out(&file);
            if(ymd->count<2){
                // 写入CSV头部
                // out << "date, Num, todo" << "\n";
                // 写入CSV数据
                out << today<<","<< l_str<<","<< i_str << "\n";


                // 关闭文件
                file.close();

                qDebug() << "Content written successfully.";
            }else{
                // 写入CSV数据
                out << today<<","<< l_str<<","<< i_str << "\n";


                // 关闭文件
                file.close();

                qDebug() << "Content written successfully.";
            }
        } else {
            qDebug() << "Error opening file!";
            // return 1;
        }



        ymd->count++;
        ui->label->setText(QString::number(ymd->count));
        ui->lineEdit->clear();


    }
};

#endif // TODAY_TODOLIST_H
