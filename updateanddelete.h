#ifndef UPDATEANDDELETE_H
#define UPDATEANDDELETE_H
#include "year_month_day.h"
#include <QWidget>
#include<QDebug>
#include<QFile>
#include <unordered_map>
#include<QLineEdit>
#include<QLabel>
#include<QVBoxLayout>
#include<QPushButton>
#include<QDebug>
namespace Ui {
class UpdateAndDelete;
}

class UpdateAndDelete : public QWidget
{
    Q_OBJECT

public:
    UpdateAndDelete(QWidget *parent,year_month_day *ymd,int choosedYear,int choosedMonth,int choosedDay);
    ~UpdateAndDelete();
    QList<QString> strList;
    year_month_day *ymd;
    int choosedYear;
    int choosedMonth;
    int choosedDay;
    QVBoxLayout *vlayout;
private:
    Ui::UpdateAndDelete *ui;
private slots:
    QList<QList<QString>> groupValues(const QList<QString>& originalList) {
        // 使用哈希表记录每个元素对应的子列表
        std::unordered_map<QString, QList<QString>> valueLists;

        // 遍历原始列表，将相同元素添加到相应的子列表
        for (QString value : originalList) {
            QString value2 = value.split(",")[0];
            valueLists[value2].push_back(value);
        }

        // 将哈希表的值（子列表）提取到一个新的 QList 中
        QList<QList<QString>> result;
        for (const auto& pair : valueLists) {
            result.push_back(pair.second);
        }

        return result;
    }
    void updatel(QHBoxLayout *hlayout,QLabel *label,int num,int y,int m,int d){
        // QWidget *qW = new QWidget;
        // QLabel *label = new QLabel(this);
        // QLineEdit *lineEdit = new QLineEdit(this);

        // qW->addWidget()
        // hlayout->removeWidget(label);
        // 移除第3个位置的子部件
        int indexToRemove = 2;
        QLayoutItem *item = hlayout->itemAt(indexToRemove);
        if (item) {
            QWidget *widgetToRemove = item->widget();
            hlayout->removeWidget(widgetToRemove);
            delete widgetToRemove;  // 如果需要，手动删除被移除的部件
        } else {
            qDebug() << "Invalid index 2 for removal.";
        }
        QLineEdit *lineEdit = new QLineEdit;
        hlayout->insertWidget(2,lineEdit);
        QPushButton *qB = new QPushButton;
        qB->setText("确定");
        hlayout->insertWidget(3,qB);

        this->repaint();
        connect(qB, &QPushButton::clicked, this, [=](){
            updatec(lineEdit,num,hlayout,y,m,d);
        });



    }
    void updatec(QLineEdit *lineEdit,int n,QHBoxLayout *hlayout,int y,int m,int d){
        qDebug()<<"更新"<<QString::number(n);
        QString update_value = lineEdit->text();
        QList<QList<QString>> groupedLists = groupValues(strList);

        //下面进行更新元素
        for(int i=0;i<groupedLists.size();i++){
            for(int j=0;j<groupedLists[i].size();j++){
                qDebug()<<QString::number(i)<<QString::number(j)<<groupedLists[i][j];
                QString ymd = QString::number(y)+"-"+QString::number(m)+"-"+QString::number(d);
                if(j==n-1&&groupedLists[i][j].contains(ymd)){
                    groupedLists[i][j]=groupedLists[i][j].split(",")[0]+","+groupedLists[i][j].split(",")[1]+","+update_value;

                }
            }
            qDebug()<<"\n";
        }
        // 创建一个 QFile 对象
        QFile file("data.csv");

                // 打开文件，如果不存在则创建
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    // 创建一个 QTextStream 对象，并将其绑定到 QFile
                    QTextStream out(&file);

                    for(QList<QString> qL:groupedLists){

                        for(QString qS:qL){
                            qDebug()<<qS;
                            QString ymd = qS.split(",")[0];
                            QString num_s = qS.split(",")[1];
                            QString content = qS.split(",")[2];

                            // 写入CSV数据
                            out << ymd<<","<< num_s<<","<< content << "\n";
                        }

                    }

                    // 关闭文件
                    file.close();

                    qDebug() << "Content written successfully.";

                } else {
                    qDebug() << "Error opening file!";
                    // return 1;
                }




                // 移除第3个位置的子部件
                int indexToRemove = 2;
                QLayoutItem *item = hlayout->itemAt(indexToRemove);
                if (item) {
                    QWidget *widgetToRemove = item->widget();
                    hlayout->removeWidget(widgetToRemove);
                    delete widgetToRemove;  // 如果需要，手动删除被移除的部件
                } else {
                    qDebug() << "Invalid index 2 for removal.";
                }

                // 移除第4个位置的子部件
                int indexToRemove2 = 3;
                QLayoutItem *item2 = hlayout->itemAt(indexToRemove2);
                if (item) {
                    QWidget *widgetToRemove = item2->widget();
                    hlayout->removeWidget(widgetToRemove);
                    delete widgetToRemove;  // 如果需要，手动删除被移除的部件
                } else {
                    qDebug() << "Invalid index 3 for removal.";
                }

                QLabel *l3 = new QLabel;
                l3->setText(update_value);
                hlayout->insertWidget(2,l3);
                // hlayout->removeWidget(lineEdit);
                // hlayout->removeWidget(qB);
                this->repaint();


    }
    void deleteAllSubwidget(QLayout *layout){
        for (int i = 0; i < layout->count(); i++) {
            int indexToRemove = i;
            QLayoutItem *item = layout->itemAt(indexToRemove);
            if (item) {
                QWidget *widgetToRemove = item->widget();
                layout->removeWidget(widgetToRemove);
                delete widgetToRemove;  // 如果需要，手动删除被移除的部件
            } else {
                qDebug() << "Invalid index for removal.";
            }
        }
    }
    void deletel(int num,QHBoxLayout *hlayout,int y,int m,int d){
        // hlayout->removeWidget(l1);
        // hlayout->removeWidget(l2);
        // hlayout->removeWidget(l3);
        deleteAllSubwidget(hlayout);
        // vlayout->removeItem(hlayout);
        // delete hlayout;

        int indexToRemove = num;
        QLayoutItem *item = vlayout->itemAt(indexToRemove);
        if (item) {
            QLayout *layoutToRemove = item->layout();
            vlayout->removeItem(layoutToRemove);
            delete layoutToRemove;  // 如果需要，手动删除被移除的部件
        } else {
            qDebug() << "Invalid index for layout removal.";
        }
        this->repaint();
        QList<QList<QString>> groupedLists = groupValues(strList);
        //下面进行删除元素
        for(int i=0;i<groupedLists.size();i++){
            for(int j=0;j<groupedLists[i].size();j++){
                QString ymd = QString::number(y)+"-"+QString::number(m)+"-"+QString::number(d);
                if(j==num-1&&groupedLists[i][j].contains(ymd)){
                    groupedLists[i].removeAt(j);
                }
            }
        }
        // 创建一个 QFile 对象
        QFile file("data.csv");

                // 打开文件，如果不存在则创建
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    // 创建一个 QTextStream 对象，并将其绑定到 QFile
                    QTextStream out(&file);

                    for(QList<QString> qL:groupedLists){

                        for(QString qS:qL){
                            QString ymd = qS.split(",")[0];
                            QString num_s = qS.split(",")[1];
                            QString content = qS.split(",")[2];
                            if(num_s.toInt()>num){
                                // 写入CSV数据
                                out << ymd<<","<< QString::number(num_s.toInt()-1)<<","<< content << "\n";
                            }else{
                                // 写入CSV数据
                                out << ymd<<","<< num_s<<","<< content << "\n";
                            }

                        }

                    }

                    // 关闭文件
                    file.close();

                    qDebug() << "Content written successfully.";

                } else {
                    qDebug() << "Error opening file!";
                    // return 1;
                }

    }

protected :
    void focusOutEvent(QFocusEvent *event) override {
        // 当组件失去焦点时，执行相应的操作
        qDebug() << "Update_and_delete Widget lost focus";

        // this->QWidget::close();
        // 调用基类的实现，确保其他事件处理函数得到调用
        QWidget::focusOutEvent(event);

    }
};

#endif // UPDATEANDDELETE_H
