#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // new 一个对象 QPushButton
    button = new QPushButton;
    //构造函数时，指定父对象
    //button = new QPushButton(this);
    //构造函数时 指定父对象和设置文本
    button = new QPushButton("按钮点这里",this);
    //this->resize(600,600);
    //如果不给按钮指定父对象，那么按钮和窗口是单独显示；如果给按钮指定了父对象，只要父对象显示，那么按钮也会显示
    button->show();
    //指定按钮的父类是窗口
    //button->setParent(this);

    button->resize(100,100);    //设置按钮的大小
    button->move(100,100);      //设置按钮在窗口的位置
    //button->setText("按钮点这里"); // 设置按钮的文本

}

Widget::~Widget()
{
}

