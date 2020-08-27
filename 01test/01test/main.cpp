#include "widget.h"     //

#include <QApplication> //QT的框架头文件
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);     //QT框架初始化
    Widget w;   // 定义一个窗口对象

    qDebug()<<"hello world";

    w.resize(600, 600);
    w.setWindowTitle("Hello World");

    w.show();   //将创建的窗口控件显示
    qDebug()<<"test of test 世界你好！";

    return a.exec(); // a.exec() 作用是让程序不死 类似于while(1) 循环 循环检测事件的产生
}
