#include "index.h"
#include "ui_index.h"
// #include
Index::Index(QWidget *parent)
    : QWidget(parent)
    , index_ui(new Ui::Index) {
    index_ui->setupUi(this);
    // index_ui->pushButton1
    connect(index_ui->pushButton_1, &QPushButton::clicked, this, &Index::onButton1Click);
    // index_ui->pushButton2
    connect(index_ui->pushButton_2, &QPushButton::clicked, this, &Index::onButton2Click);
    // index_ui->pushButton3
    connect(index_ui->pushButton_3, &QPushButton::clicked, this, &Index::onButton3Click);

}
Index::~Index()
{
    delete index_ui;
}
