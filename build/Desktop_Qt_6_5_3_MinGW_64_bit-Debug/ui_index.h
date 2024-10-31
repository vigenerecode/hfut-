/********************************************************************************
** Form generated from reading UI file 'index.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_H
#define UI_INDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Index
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Index)
    {
        if (Index->objectName().isEmpty())
            Index->setObjectName("Index");
        Index->resize(887, 649);
        pushButton_1 = new QPushButton(Index);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(290, 110, 111, 41));
        pushButton_2 = new QPushButton(Index);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 190, 111, 41));
        pushButton_3 = new QPushButton(Index);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(290, 270, 111, 41));

        retranslateUi(Index);

        QMetaObject::connectSlotsByName(Index);
    } // setupUi

    void retranslateUi(QWidget *Index)
    {
        Index->setWindowTitle(QCoreApplication::translate("Index", "Form", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Index", "\346\227\245\345\216\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Index", "\346\227\266\351\222\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Index", "\350\276\223\345\205\245\344\273\212\346\227\245\345\276\205\345\212\236\344\272\213\345\256\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Index: public Ui_Index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_H
