#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //把父对象置空
    this->setParent(nullptr);
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onButtonClick);
}

// void Ui::~Widget()

Widget::~Widget()
{
    delete ui;
}
