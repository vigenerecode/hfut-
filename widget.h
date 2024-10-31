#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include<QMessageBox>
#include "index.h"
// #include "mywidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent);// = nullptr
    ~Widget();
    // void paintEvent(QPaintEvent *event);
    // void onButtonClick();
    Ui::Widget *ui;

private slots:
    void onButtonClick(){
        QString account = ui->lineEdit->text();
        QString passwd = ui->lineEdit_2->text();
        if(account=="admin"&&passwd=="123456"){
            //
            delete this;
            Index *index = new Index(nullptr);

            index->show();

        }else{
            QMessageBox::information(this, "提示", "您输入的账户名或者密码不合法admin+123456");
        }
    }
};
#endif // WIDGET_H
