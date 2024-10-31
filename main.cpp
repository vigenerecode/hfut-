// #include "mywidget.h"
#include "widget.h"
// #include<iostream>
#include <QApplication>
//#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *w = new Widget(nullptr);
    w->show();
    return a.exec();
}
