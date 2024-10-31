#include "today_todolist.h"
#include "ui_today_todolist.h"

Today_TodoList::Today_TodoList(QWidget *parent,QString l)
    : QWidget(parent)
    , ui(new Ui::Today_TodoList)
{
    ui->setupUi(this);
    // ui->setupUi(this);

    // ui->lineEdit->text();
    ymd = new year_month_day();
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Today_TodoList::onCloseButtonClick);
    if(l==""){
        connect(ui->pushButton, &QPushButton::clicked, this, &Today_TodoList::onButtonClick);
    }else{
        this->setParent(parent);
        ui->label_2->setText("输入"+l+"待办");
        ll_today = l;
        connect(ui->pushButton, &QPushButton::clicked, this, &Today_TodoList::onButtonClick2);
        this->repaint();
    }


}

// Today_TodoList* Today_TodoList::Toady_TodoList(QString l)
// {
//     ll_today = l;

//     connect(ui->pushButton, &QPushButton::clicked, this, &Today_TodoList::onButtonClick2);
//     return this;
// }

// Today_TodoList::Today_TodoList(QString l)
// {

// }

Today_TodoList::~Today_TodoList()
{
    delete ui;
}
