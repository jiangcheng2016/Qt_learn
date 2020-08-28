#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //代码可以写在这里
    //设置窗口属性
    this->setWindowTitle("你好，世界！"); //设置窗口标题
    this->resize(600,600);  //设置窗口大小，不可拉伸
    this->setFixedSize(600,400);    //设置窗口大小，不可拉伸

}

Widget::~Widget()
{
}

