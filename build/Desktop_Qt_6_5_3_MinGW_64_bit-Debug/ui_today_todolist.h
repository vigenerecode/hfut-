/********************************************************************************
** Form generated from reading UI file 'today_todolist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODAY_TODOLIST_H
#define UI_TODAY_TODOLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Today_TodoList
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Today_TodoList)
    {
        if (Today_TodoList->objectName().isEmpty())
            Today_TodoList->setObjectName("Today_TodoList");
        Today_TodoList->resize(722, 620);
        label = new QLabel(Today_TodoList);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 270, 16, 31));
        lineEdit = new QLineEdit(Today_TodoList);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(270, 270, 311, 31));
        pushButton = new QPushButton(Today_TodoList);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 270, 75, 23));
        label_2 = new QLabel(Today_TodoList);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 220, 201, 31));
        tableWidget = new QTableWidget(Today_TodoList);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(210, 210, 501, 251));
        pushButton_2 = new QPushButton(Today_TodoList);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(674, 210, 31, 21));
        tableWidget->raise();
        label_2->raise();
        label->raise();
        lineEdit->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(Today_TodoList);

        QMetaObject::connectSlotsByName(Today_TodoList);
    } // setupUi

    void retranslateUi(QWidget *Today_TodoList)
    {
        Today_TodoList->setWindowTitle(QCoreApplication::translate("Today_TodoList", "Form", nullptr));
        label->setText(QCoreApplication::translate("Today_TodoList", "1", nullptr));
        pushButton->setText(QCoreApplication::translate("Today_TodoList", "\346\217\220\344\272\244", nullptr));
        label_2->setText(QCoreApplication::translate("Today_TodoList", "              \350\276\223\345\205\245\344\273\212\346\227\245\345\276\205\345\212\236", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Today_TodoList", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Today_TodoList: public Ui_Today_TodoList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODAY_TODOLIST_H
