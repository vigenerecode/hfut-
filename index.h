#ifndef INDEX_H
#define INDEX_H
#include "mywidget.h"
#include "clock.h"
#include <QObject>
#include <QWidget>
#include "ui_index.h"
#include "today_todolist.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class Index;
}
QT_END_NAMESPACE
class Index:public QWidget
{
    Q_OBJECT
public:
    Index(QWidget *parent);
    ~Index();
    Ui::Index *index_ui;
private slots:
    void onButton1Click(){
        // delete this;
        MyWidget *my_w = new MyWidget(nullptr);



        my_w->init(my_w);
        my_w->show();
    }
    void onButton2Click(){
        // delete this;
        Clock *my_clock = new Clock(nullptr);




        my_clock->show();
    }
    void onButton3Click(){
        //留作写今日待办
        Today_TodoList *todoList = new Today_TodoList(nullptr,"");


        todoList->show();
    }
};

#endif // INDEX_H
